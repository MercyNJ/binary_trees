#include "binary_trees.h"
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max);
/**
 * binary_tree_is_bst - Check if a binary tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
  if (tree == NULL)
    return 0;
  return is_bst_helper(tree, NULL, NULL);
}
/**
 * is_bst_helper - Recursive helper function to check if a binary tree is a valid BST.
 * @tree: Pointer to the current node being checked.
 * @min: Pointer to the minimum allowed value in the tree (left boundary).
 * @max: Pointer to the maximum allowed value in the tree (right boundary).
 * Return: 1 if tree is a valid BST, otherwise 0.
 */
int is_bst_helper(const binary_tree_t *tree, const binary_tree_t *min, const binary_tree_t *max)
{
  if (tree == NULL)
    return 1;
  int left_bst = is_bst_helper(tree->left, min, tree);
  int right_bst = is_bst_helper(tree->right, tree, max);
  int current_value = tree->n;
  int min_value = (min != NULL) ? min->n : INT_MIN;
  int max_value = (max != NULL) ? max->n : INT_MAX;
  if (current_value <= min_value || current_value >= max_value)
    return 0;
  return (left_bst && right_bst);
}
