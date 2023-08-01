#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree)
{
  size_t left_height = 0, right_height = 0;

  if (tree == NULL)
    return (0);
  if (tree->left != NULL)
    left_height = 1 + binary_tree_height(tree->left);
  else
	  left_height = -1;
  if (tree->right != NULL)
    right_height = 1 + binary_tree_height(tree->right);
  else
	  right_height = -1;
  if (left_height > right_height)
    return (left_height);
  else
    return (right_height);
}

int binary_tree_balance(const binary_tree_t *tree)
{
	int b_factor = 0, left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);
	b_factor = left_h - right_h;
	return (b_factor);
}
