#include "binary_trees.h"
/**
 * create_queue_node - create a queue node
 * @node: node to create
 *
 * Return: pointer to new node
 */
queue_node_t *create_queue_node(binary_tree_t *node)
{
	queue_node_t *new_node = malloc(sizeof(queue_node_t));

	if (new_node == NULL)
		return (NULL);
	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}
/**
 * create_queue - creates queue
 *
 * Return: pointer to queue
 */
queue_t *create_queue()
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
		return (NULL);
	queue->front = queue->rear = NULL;
	return (queue);
}
/**
 * enqueue - enqueues the queue
 * @queue: pointer to queue
 * @node: pointer to node
 *
 * Return: nothing
 */
void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node;

	if (queue == NULL || node == NULL)
		return;
	new_node = create_queue_node(node);
	if (new_node == NULL)
		return;
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = new_node;
		return;
	}
	queue->rear->next = new_node;
	queue->rear = new_node;
}
/**
 * dequeue - dequeues the queue
 * @queue: pointer to the queue
 *
 * Return: pointer to node dequeued
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (queue == NULL || queue->front == NULL)
		return (NULL);
	temp = queue->front;
	queue->front = queue->front->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	node = temp->node;
	free(temp);
	return (node);
}
/**
 * is_empty - check if queue is NULL
 * Return: 1 
 */
int is_empty(queue_t *queue)
{
	return (queue == NULL || queue->front == NULL);
}
/**
 * destroy_queue - destroys the queue
 * @queue: to destroyed
 *
 * Return: nothing
 */
void destroy_queue(queue_t *queue)
{
	while (!is_empty(queue))
		dequeue(queue);
	free(queue);
}
/**
 * binary_tree_levelorder - traverses using level-order
 * @tree: pointer to root
 * @func: pointer to function that print data
 *
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;
	queue = create_queue(void);
	if (queue == NULL)
		return;
	enqueue(queue, (binary_tree_t *)tree);
	while (!is_empty(queue))
	{
		current = dequeue(queue);
		func(current->n);
		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);
	}
	destroy_queue(queue);
}
