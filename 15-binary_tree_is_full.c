#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right)
		return (1);
	if (!tree->left && !tree_right)
		return (1);
