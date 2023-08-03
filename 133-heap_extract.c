#include <stdlib.h>
// Function to get the height of the heap
int get_height(heap_t* root) {
    if (root == NULL)
        return 0;
    int left_height = get_height(root->left);
    int right_height = get_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}
// Function to swap values of two nodes
void swap_values(heap_t* node1, heap_t* node2) {
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}
// Function to rebuild the heap
void heapify_down(heap_t* root) {
    if (root == NULL)
        return;
    heap_t* max_node = root;
    if (root->left != NULL && root->left->n > max_node->n)
        max_node = root->left;
    if (root->right != NULL && root->right->n > max_node->n)
        max_node = root->right;
    if (max_node != root) {
        swap_values(root, max_node);
        heapify_down(max_node);
    }
}
int heap_extract(heap_t** root) {
    if (root == NULL || *root == NULL)
        return 0;
    // Get the value of the root node
    int extracted_value = (*root)->n;
    // Get the height of the heap
    int height = get_height(*root);
    // Find the last level-order node
    int i;
    heap_t* last_node = NULL;
    for (i = 1; i < height - 1; i++) {
        last_node = (last_node == NULL) ? *root : last_node->left;
    }
    // Traverse to the rightmost node in the last level
    if (last_node == NULL) {
        last_node = *root;
        while (last_node->right != NULL) {
            last_node = last_node->right;
        }
    } else if (last_node->right != NULL) {
        last_node = last_node->right;
        while (last_node->left != NULL) {
            last_node = last_node->left;
        }
    }
    // Replace the root with the last node
    (*root)->n = last_node->n;
    // Free the last node
    if (last_node == *root) {
        free(*root);
        *root = NULL;
    } else {
        heap_t* parent = last_node->parent;
        if (parent == NULL)
            parent = last_node;
        if (parent->left == last_node)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(last_node);
    }
    // Rebuild the heap if necessary
    if (*root != NULL)
        heapify_down(*root);
    return extracted_value;
}
