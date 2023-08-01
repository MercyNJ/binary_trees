#include "binary_trees.h"
size_t tree_height(const binary_tree_t *tree);

/**
 * tree_height - Calculates height of tree.
 *
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Height of tree, 0 if empty.
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Calculates balance factor of tree.
 *
 * @tree: Pointer to tree to get the balance factor for.
 *
 * Return: Balance factor or 0 if the tree is empty.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return (left_height - right_height);
}
