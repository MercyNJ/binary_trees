#include "binary_trees.h"
bool is_complete(const binary_tree_t *tree);
bool is_max_heap(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Check if it's a complete tree */
    if (!is_complete(tree))
        return 0;

    /* Check if the Max Heap property holds for all nodes */
    return is_max_heap(tree);
}

/**
 * is_complete - Check if the binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: True if the tree is complete, false otherwise
 */
bool is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return true;

    if (tree->left == NULL && tree->right != NULL)
        return false;

    return is_complete(tree->left) && is_complete(tree->right);
}

/**
 * is_max_heap - Check if the binary tree follows Max Heap property
 * @tree: Pointer to the root node of the tree to check
 * Return: True if the tree follows the Max Heap property, false otherwise
 */
bool is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return true;

    if (tree->left != NULL && tree->left->n > tree->n)
        return false;

    if (tree->right != NULL && tree->right->n > tree->n)
        return false;

    return is_max_heap(tree->left) && is_max_heap(tree->right);
}
