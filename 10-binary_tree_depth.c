#include "binary_trees.h"
/**
 * binary_tree_depth - Measures depth of node in a tree.
 *
 * @tree: Pointer to node to measure depth for.
 *
 * Return: Node's depth or 0 if Node is Null.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		depth += 1;
		tree = tree->parent;
	}
	return (depth);
}
