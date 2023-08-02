#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;

	if (first == NULL || second == NULL)
		return(NULL);

	while (first != NULL)
	{
		const binary_tree_t *temp = second;

		while (temp != NULL)
		{
			if (first == temp)
				return ((binary_tree_t *)first);
			temp = temp->parent;
		}
		first = first->parent;
	}
	return ((binary_tree_t *)ancestor);
}
