#include "binary_trees.h"
/**
 * bst_search - Search for a value in a Binary Search Tree (BST).
 * @tree: Pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: A pointer to the node containing the value, or NULL if not found.
 */
binary_tree_t *bst_search(const binary_tree_t *tree, int value) {
  if (tree == NULL) {
    return NULL; // Base case: Tree is empty or value not found
  }
  if (value == tree->n) {
    return (binary_tree_t *)tree; // Value found, return the current node
  } else if (value < tree->n) {
    return bst_search(tree->left, value); // Search in the left subtree
  } else {
    return bst_search(tree->right, value); // Search in the right subtree
  }
}
