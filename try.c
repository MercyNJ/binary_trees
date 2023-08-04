#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
  int n;
  struct binary_tree_s *parent;
  struct binary_tree_s *left;
  struct binary_tree_s *right;
};
typedef struct binary_tree_s heap_t;

// Function to swap values of two nodes
void swap_values(heap_t *node1, heap_t *node2)
{
  int temp = node1->n;
  node1->n = node2->n;
  node2->n = temp;
}

// Function to get the height of a binary tree
int get_height(heap_t *root)
{
  if (root == NULL)
    return 0;
  int left_height = get_height(root->left);
  int right_height = get_height(root->right);
  return (left_height > right_height ? left_height + 1 : right_height + 1);
}

// Function to move down the node to the appropriate position in the Max Heap
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

int heap_extract(heap_t **root)
{
  if (root == NULL || *root == NULL)
    return 0;

  int extracted_value = (*root)->n;

  // Find the last level-order node
  int height = get_height(*root);
  heap_t *last_node_parent = *root;
  int mask = 1 << (height - 2); // Start with the second-to-last level
  while (mask > 0)
    {
      if (mask & 1) // Right child
	{
	  if (last_node_parent->right != NULL)
	    last_node_parent = last_node_parent->right;
	  else
	    last_node_parent = last_node_parent->left;
	}
      else // Left child
	{
	  last_node_parent = last_node_parent->left;
	}
      mask >>= 1;
    }

  heap_t *last_node = last_node_parent->right;
  if (last_node == NULL)
    last_node = last_node_parent->left;

  if (last_node_parent->right != NULL)
    last_node_parent->right = NULL;
  else
    last_node_parent->left = NULL;

  if (*root == last_node)
    {
      free(*root);
      *root = NULL;
      return extracted_value;
    }

  // Swap the values of the root node and the last level-order node
  (*root)->n = last_node->n;
  free(last_node);

  // Move down the new root to the appropriate position
  heapify_down(*root);

  return extracted_value;
}
