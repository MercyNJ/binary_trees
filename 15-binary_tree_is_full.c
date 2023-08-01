#include "binary_trees.h"

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
