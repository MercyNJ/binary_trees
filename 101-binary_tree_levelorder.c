#include "binary_trees.h"
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *));
	if (queue == NULL)
		return;
	int front = 0, rear = 0;
	queue[rear++] = tree;
	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];
		func(current->n);
		if (current->left != NULL)
		{
			const binary_tree_t **temp = malloc(sizeof(binary_tree_t *) * (rear + 1));
			if (temp == NULL)
			{
				free(queue);
				return;
			}
			for (int i = 0; i < rear; i++)
				temp[i] = queue[i];
			temp[rear++] = current->left;
			free(queue);
			queue = temp;
		}
		if (current->right != NULL)
		{
			const binary_tree_t **temp = malloc(sizeof(binary_tree_t *) * (rear + 1));
			if (temp == NULL)
			{
				free(queue);
				return;
			}
			for (int i = 0; i < rear; i++)
				temp[i] = queue[i];
			temp[rear++] = current->right;
			free(queue);
			queue = temp;
		}
	}
	free(queue);
}
