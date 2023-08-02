#include "binary_trees.h"
bst_t *bst_insert_recursive(bst_t *tree, int value);
/**
 * bst_insert - Insert a value in a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
  if (tree == NULL)
    return NULL;
  if (*tree == NULL)
    {
      *tree = binary_tree_node(NULL, value);
      return *tree;
    }
  return bst_insert_recursive(*tree, value);
}
/**
 * bst_insert_recursive - Recursively insert a value in a BST.
 * @tree: Pointer to the current node in the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert_recursive(bst_t *tree, int value)
{
  if (value == tree->n)
    return NULL;
  if (value < tree->n)
    {
      if (tree->left == NULL)
	{
	  tree->left = binary_tree_node(tree, value);
	  return tree->left;
	}
      return bst_insert_recursive(tree->left, value);
    }
  if (value > tree->n)
    {
      if (tree->right == NULL)
	{
	  tree->right = binary_tree_node(tree, value);
	  return tree->right;
	}
      return bst_insert_recursive(tree->right, value);
    }
  return NULL;
}
