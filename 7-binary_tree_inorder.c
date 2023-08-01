#include "binary_trees.h"
/**
 * binary_tree_inorder - traverses using pre-oder
 * @tree: pointer to root
 * @func: prints the data in node
 *
 * Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
