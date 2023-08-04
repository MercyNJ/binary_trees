#include "binary_trees.h"

int get_last_level_order_node(heap_t* root) {
    int last_node_value = root->n;
    int max_nodes = 1000;
    heap_t** queue = (heap_t**)malloc(max_nodes * sizeof(heap_t*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        heap_t* current = queue[front++];
        last_node_value = current->n;
        if (rear == max_nodes) {
            max_nodes *= 2;
            queue = (heap_t**)realloc(queue, max_nodes * sizeof(heap_t*));
        }
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    free(queue);
    return last_node_value;
}

void heapify_down(heap_t* root) {
    heap_t* current = root;
    while (1) {
        heap_t* max_child = NULL;
        if (current->left && current->left->n > current->n) {
            max_child = current->left;
        }
        if (current->right && current->right->n > (max_child ? max_child->n : current->n)) {
            max_child = current->right;
        }

        if (max_child && max_child->n > current->n) {
            int temp = current->n;
            current->n = max_child->n;
            max_child->n = temp;
            current = max_child;
        } else {
            break;
        }
    }
}

int heap_extract(heap_t** root) {
    if (!*root) return 0;

    int extracted_value = (*root)->n;
    heap_t* last_node = NULL;

    if (!(*root)->left && !(*root)->right) {
        free(*root);
        *root = NULL;
    } else {
        int last_node_value = get_last_level_order_node(*root);
        int max_nodes = 1000;
        heap_t** queue = (heap_t**)malloc(max_nodes * sizeof(heap_t*));
        int front = 0, rear = 0;
        queue[rear++] = *root;

        while (front < rear) {
            heap_t* current = queue[front++];
            if (current->n == last_node_value) {
                last_node = current;
            }
            if (rear == max_nodes) {
                max_nodes *= 2;
                queue = (heap_t**)realloc(queue, max_nodes * sizeof(heap_t*));
            }
            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;
        }

        free(queue);

        if (last_node) {
            (*root)->n = last_node->n;
            free(last_node);
            last_node = NULL;
            heapify_down(*root);
        }
    }

    return extracted_value;
}
