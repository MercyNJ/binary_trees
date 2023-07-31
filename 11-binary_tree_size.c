#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, left_s = 0, right_s = 0;

	if (tree == NULL)
		return (0);
	left_s = binary_tree_size(tree->left);
	right_s = binary_tree_size(tree->right);
	size = left_s + right_s + 1;
	return (size);
}
