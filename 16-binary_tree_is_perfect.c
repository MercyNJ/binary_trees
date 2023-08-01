#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of the tree
 * @tree: root of the tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    if (tree->left != NULL)
        left_height = 1 + binary_tree_height(tree->left);

    if (tree->right != NULL)
        right_height = 1 + binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int l_height, r_height, l_status, r_status;

        if (tree == NULL)
        return (0);

        if (!tree->left && !tree->right)
            return (1);
	
	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	
        if (l_height == r_height)
	{
		l_status = binary_tree_is_perfect(tree->left);
		r_status = binary_tree_is_perfect(tree->right);
		return (l_status && r_status);
	}

   	return (0);
}
