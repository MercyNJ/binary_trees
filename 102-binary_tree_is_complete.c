#include "binary_trees.h"
#define QUEUE_SIZE 1024

<<<<<<< HEAD

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree) {
    if (tree == NULL) {
        return 0;
    }

    int flag = 0;
    const binary_tree_t **queue = (const binary_tree_t **)malloc(sizeof(const binary_tree_t *));
    int front = 0, rear = 0;

    queue[rear++] = tree;

    while (front < rear) {
        const binary_tree_t *node = queue[front++];

        if (node->left) {
            if (flag) {
                free(queue);
                return 0;
            }
            queue = (const binary_tree_t **)realloc(queue, (rear + 1) * sizeof(const binary_tree_t *));
            queue[rear++] = node->left;
        } else {
            flag = 1;
        }

        if (node->right) {
            if (flag) {
                free(queue);
                return 0;
            }
            queue = (const binary_tree_t **)realloc(queue, (rear + 1) * sizeof(const binary_tree_t *));
            queue[rear++] = node->right;
        } else {
            flag = 1;
        }
    }

    free(queue);
    return 1;
=======
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *queue[QUEUE_SIZE], *current;
	int front = 0, rear = 0;
	int is_last_l = 0;

	if (tree == NULL)
		return (0);
	//queue = malloc(QUEUE_SIZE * sizeof(binary_tree_t));
	queue[rear++] = tree;
	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
			is_last_l = 1;
		else if (is_last_l)
			return (0);
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
>>>>>>> 1700c36 (103 110 111 112 113)
}
