#include "binary_trees.h"

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t* grandp;

	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);

	grandp = node->parent->parent;

	if (grandp->left == NULL || grandp->right == NULL)
		return (NULL);
	else
		return ((node->parent == grandp->left) ? grandp->right : grandp->left);
}


