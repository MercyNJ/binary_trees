#include "binary_trees.h"

void swap_values(heap_t *node1, heap_t *node2)
{
  int temp = node1->n;
  node1->n = node2->n;
  node2->n = temp;
}

int get_height(heap_t *root)
{
  if (root == NULL)
    return 0;
  int left_height = get_height(root->left);
  int right_height = get_height(root->right);
  return (left_height > right_height ? left_height + 1 : right_height + 1);
}

void heapify_down(heap_t *root)
{
  if (root == NULL)
    return;

  heap_t *largest = root;
  heap_t *left_child = root->left;
  heap_t *right_child = root->right;

  if (left_child != NULL && left_child->n > largest->n)
    largest = left_child;

  if (right_child != NULL && right_child->n > largest->n)
    largest = right_child;

  if (largest != root)
    {
      swap_values(root, largest);
      heapify_down(largest);
    }
}

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
  if (heap == NULL)
    return NULL;

  int heap_size = 0;
  int *sorted_array = NULL;

  heap_t *temp = heap;
  while (temp != NULL)
    {
      heap_size++;
      temp = temp->left;
    }

  sorted_array = (int *)malloc(heap_size * sizeof(int));
  if (sorted_array == NULL)
    return NULL;

  for (int i = 0; i < heap_size; i++)
    {
      sorted_array[i] = heap_extract(&heap);
      heapify_down(heap);
    }

  *size = heap_size;
  return sorted_array;
}
