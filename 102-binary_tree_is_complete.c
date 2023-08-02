#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *queue, *current;
	int front = 0, rear = 0;
	int is_last_l = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t));
	if (queue == NULL)
		return (0);
	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
			is_last_l = 1;
		else if (is_last_l)
			return (0);
		func(current->n);
		if (current->left != NULL)
			queue[rear++] = current->left;
		else
			is_last_l = 1;
		if (current->right != NULL)
			queue[rear++] = current->right;
		else
			is_last_l = 1;
	}
	return (1);
}
