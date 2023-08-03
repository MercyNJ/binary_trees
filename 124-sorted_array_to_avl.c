#include "binary_trees.h"
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the sorted array.
 * @start: Starting index of the current subarray.
 * @end: Ending index of the current subarray.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *build_avl(int *array, int start, int end)
{
    int mid;
    avl_t *root;
    if (start > end)
        return NULL;
    mid = (start + end) / 2;
    root = binary_tree_node(NULL, array[mid]);
    if (!root)
        return NULL;
    root->left = build_avl(array, start, mid - 1);
    root->right = build_avl(array, mid + 1, end);
    if (root->left)
        root->left->parent = root;
    if (root->right)
        root->right->parent = root;
    return root;
}
/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;
    return build_avl(array, 0, size - 1);
}
