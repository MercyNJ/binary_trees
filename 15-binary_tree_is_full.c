#include "binary_trees.h"
/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to root node of tree to check.
 *
 * Return: 1 if full, 0 otherwise.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_status, right_status;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && tree->right)
	{
		left_status = binary_tree_is_full(tree->left);
		right_status = binary_tree_is_full(tree->right);
		return (left_status && right_status);
	}
	return (0);
}
