#include "binary_trees.h"
/**
 * binary_tree_height - calculates the height of the tree
 * @tree: root the tree
 *
 * Return: height of the tree
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
