#include "binary_trees.h"

/**
 * swap - Swaps the values of two binary tree nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap(binary_tree_t *node1, binary_tree_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}

/**
 * heapify_up - Moves the newly inserted node up to maintain Max Heap property.
 * @node: Pointer to the newly inserted node.
 */
void heapify_up(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	while (parent != NULL && node->n > parent->n)
	{
		swap(node, parent);
		node = parent;
		parent = parent->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
binary_tree_t *heap_insert(binary_tree_t **root, int value)
{
	binary_tree_t *current;
	binary_tree_t *new_node = binary_tree_node(NULL, value);

	if (root == NULL)
		return (NULL);

	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	current = *root;
	while (current->left != NULL && current->right != NULL)
	{
		if (current->left->n >= current->right->n)
			current = current->left;
		else
			current = current->right;
	}

	if (current->left == NULL)
	{
		current->left = new_node;
	}
	else
	{
		current->right = new_node;
	}

	new_node->parent = current;

	/* Step 5: Move the new node up to its correct position in the heap */
	heapify_up(new_node);

	return (new_node);
}
