#include "binary_trees.h"
int avl_height_and_balance(const binary_tree_t *tree, int *balance_factor);
avl_t *avl_insert_and_balance(avl_t **tree, avl_t *parent,
			      avl_t **new_node, int value);
avl_t *avl_insert(avl_t **tree, int value);
/**
 * avl_height_and_balance - Calculates the height and
 *        balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to
 *        calculate the height and balance factor.
 * @balance_factor: A pointer to an integer to
 *        store the balance factor of the tree.
 *
 * Return: The height of the tree.
 */
int avl_height_and_balance(const binary_tree_t *tree, int *balance_factor)
{
	int left_height;
	int right_height;

	if (tree == NULL)
	{
		*balance_factor = 0;
		return (0);
	}
	left_height = avl_height_and_balance(tree->left, balance_factor);
	right_height = avl_height_and_balance(tree->right, balance_factor);
	*balance_factor = left_height - right_height;
	return (left_height > right_height ? left_height + 1 : right_height + 1);
}
/**
 * avl_insert_and_balance - Inserts a value into an
 *      AVL tree recursively and balances it.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_and_balance(avl_t **tree, avl_t *parent,
			      avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_and_balance(&(*tree)->left,
				*tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_and_balance(&(*tree)->right,
				*tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	avl_height_and_balance(*tree, &balance_factor);
	if (balance_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_and_balance(tree, *tree, &new_node, value);
	return (new_node);
}
