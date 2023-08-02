#include "binary_trees.h"
#define QUEUE_SIZE 1024

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	const binary_tree_t *queue[QUEUE_SIZE];
	int front = 0, rear = 0;
	queue[rear++] = tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];
		func(current->n);
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}
