#include "binary_trees.h"
/**
 * binary_tree_height - Calculates height of tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Height of tree, 0 if empty.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_height = 1 + binary_tree_height(tree->right);
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - Calculates balance factor of tree.
 *
 * @tree: Pointer to tree to get balance factor for.
 *
 * Return: Balance factor or 0 if tree is empty.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	/*int b_factor, left_h, right_h;*/
	if (tree == NULL)
		return (0);
	/**
	 * left_h = binary_tree_height(tree->left);
	 * right_h = binary_tree_height(tree->right);
	 * b_factor = left_h - right_h;
	 */
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
