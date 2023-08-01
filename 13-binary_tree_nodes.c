#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_n = 0, right_n = 0;
	size_t no_of_nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		no_of_nodes = 1;
	left_n = binary_tree_nodes(tree->left);
	right_n = binary_tree_nodes(tree->right);
	no_of_nodes += left_n + right_n;
	return (no_of_nodes);
}
