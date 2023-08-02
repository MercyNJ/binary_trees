#include "binary_trees.h"
#define QUEUE_SIZE 1024
int binary_tree_is_complete(const binary_tree_t *tree)
{
  const binary_tree_t **queue, *current;
  int front = 0, rear = 0;

  if (tree == NULL)
    return (0);

  queue = malloc(QUEUE_SIZE * sizeof(binary_tree_t *));
  if (queue == NULL)
    return (0);

  queue[rear++] = tree;

  while (front < rear)
    {
      current = queue[front++];
      if (current == NULL)
	return (0); // If we encounter a NULL node, the tree is not complete

      // Enqueue the left and right children
      queue[rear++] = current->left;
      queue[rear++] = current->right;
    }

  // If we reach this point, the tree is complete
  free(queue);
  return (1);
}
