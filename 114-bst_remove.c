#include <stddef.h>
#include "binary_trees.h"

/**
 * bst_minimum - Finds the minimum node (leftmost) in a BST.
 * @tree: Pointer to the root node of the BST.
 *
 * Return: Pointer to the minimum node or NULL if tree is NULL.
 */
bst_t *bst_minimum(bst_t *tree)
{
	if (tree == NULL)
		return (NULL);
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to new root node of tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			if (temp)
				temp->parent = root->parent;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			if (temp)
				temp->parent = root->parent;

			free(root);
			return (temp);
		}
		bst_t *in_order_successor = bst_minimum(root->right);

		root->n = in_order_successor->n;

		root->right = bst_remove(root->right, in_order_successor->n);
	}
	return (root);
}
