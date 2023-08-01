#include "binary_trees.h"
/**
 * binary_tree_leaves - Counts no of leaves in tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: No of leaves in tree,0 if empty.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_l = 0, right_l = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_l = binary_tree_leaves(tree->left);
	right_l = binary_tree_leaves(tree->right);
	return (left_l + right_l);
}
