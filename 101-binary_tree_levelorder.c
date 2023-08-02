#include "binary_trees.h"
/**
 * enqueue_node - enqueues a nodes
 * @node: to be enqueued
 * @queue: adds a node to queue
 * @rear: used to traverse
 *
 * Return: nothing
 */
void enqueue_node(const binary_tree_t *node,
		const binary_tree_t **queue, int *rear)
{
	queue[(*rear)++] = node;
}
/**
 * dequeue_node - dequeues a node
 * @queue: adds a node to the queue
 * @front: traverses foward
 *
 * Return: pointer to front queues
 */
const binary_tree_t *dequeue_node(const binary_tree_t **queue, int *front)
{
	return (queue[(*front)++]);
}
/**
 * binary_tree_levelorder - traverse using the level-order
 * @tree: root of the tree
 * @func: function pointer to display the values
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *));

	if (queue == NULL)
		return;
	int front = 0, rear = 0;

	enqueue_node(tree, queue, &rear);
	while (front < rear)
	{
		const binary_tree_t *current = dequeue_node(queue, &front);

		func(current->n);
		if (current->left != NULL)
			enqueue_node(current->left, queue, &rear);
		if (current->right != NULL)
			enqueue_node(current->right, queue, &rear);
	}
	free(queue);
}
