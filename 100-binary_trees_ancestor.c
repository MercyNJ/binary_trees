#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to the ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{

	if (first == NULL || second == NULL)
		return (NULL);

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
	return (NULL);
}
