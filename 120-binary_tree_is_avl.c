#include "binary_trees.h"
#include "limits.h"
/* Function to measure the height of a binary tree */
size_t measure_height(const binary_tree_t *tree)
{
  if (tree != NULL)
    {
      size_t left_height = 0, right_height = 0;
      left_height = tree->left ? 1 + measure_height(tree->left) : 1;
      right_height = tree->right ? 1 + measure_height(tree->right) : 1;
      return (left_height > right_height) ? left_height : right_height;
    }
  return 0;
}
/* Function to check if a binary tree is a valid AVL tree */
int check_avl_properties(const binary_tree_t *tree, int min_value, int max_value)
{
  size_t left_height, right_height, height_diff;
  if (tree != NULL)
    {
      if (tree->n < min_value || tree->n > max_value)
	return 0;
      left_height = measure_height(tree->left);
      right_height = measure_height(tree->right);
      height_diff = (left_height > right_height) ? left_height - right_height : right_height - left_height;
      if (height_diff > 1)
	return 0;
      return (check_avl_properties(tree->left, min_value, tree->n - 1) &&
	      check_avl_properties(tree->right, tree->n + 1, max_value));
    }
  return 1;
}
/* Main function to check if a binary tree is a valid AVL tree */
int binary_tree_is_avl(const binary_tree_t *tree)
{
  if (tree == NULL)
    return 0;
  return check_avl_properties(tree, INT_MIN, INT_MAX);
}
