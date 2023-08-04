#include "binary_trees.h"
/**
 * avl_rebalance - Rebalances an AVL Tree after removal.
 * @node: Pointer to the current node to start rebalancing from.
 *
 * Return: Pointer to the new root node of
 *    the subtree after rebalancing.
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance;

	if (node == NULL)
		return (NULL);
	balance = binary_tree_balance(node);
	if (balance > 1 && binary_tree_balance(node->left) >= 0)
		return (binary_tree_rotate_right(node));
	if (balance < -1 && binary_tree_balance(node->right) <= 0)
		return (binary_tree_rotate_left(node));
	if (balance > 1 && binary_tree_balance(node->left) < 0)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}
	if (balance < -1 && binary_tree_balance(node->right) > 0)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}
/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of
 *       the tree after removing the value.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				free(root);
				root = NULL;
			}
			else
			{
				*root = *temp;
				free(temp);
			}
		}
		else
		{
			temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (root == NULL)
		return (NULL);
	root = avl_rebalance(root);
	return (root);
}
