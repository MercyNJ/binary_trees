#include "binary_trees.h"
/**
 * avl_rebalance - Rebalances an AVL Tree after removal.
 * @node: Pointer to the current node to start rebalancing from.
 *
 * Return: Pointer to the new root node of the subtree after rebalancing.
 */
avl_t *avl_rebalance(avl_t *node)
{
    int balance;
    if (node == NULL)
        return (NULL);
    balance = binary_tree_balance(node);
    /* Left-Left case */
    if (balance > 1 && binary_tree_balance(node->left) >= 0)
        return binary_tree_rotate_right(node);
    /* Right-Right case */
    if (balance < -1 && binary_tree_balance(node->right) <= 0)
        return binary_tree_rotate_left(node);
    /* Left-Right case */
    if (balance > 1 && binary_tree_balance(node->left) < 0)
    {
        node->left = binary_tree_rotate_left(node->left);
        return binary_tree_rotate_right(node);
    }
    /* Right-Left case */
    if (balance < -1 && binary_tree_balance(node->right) > 0)
    {
        node->right = binary_tree_rotate_right(node->right);
        return binary_tree_rotate_left(node);
    }
    return (node);
}
/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 *
 * Return: A pointer to the new root node of the tree after removing the value.
 */

avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return (NULL);
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        // Node with the value found, perform removal
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;
            // No child or one child case
            if (temp == NULL)
            {
                free(root);
                root = NULL;
            }
            else
            {
                *root = *temp; // Copy the contents of the child node
                free(temp);
            }
        }
        else
        {
            // Two children case, find the in-order successor
            avl_t *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->n = temp->n; // Copy the value of the in-order successor
            root->right = avl_remove(root->right, temp->n); // Remove in-order successor
        }
    }
    // If the tree had only one node, return
    if (root == NULL)
        return (NULL);
    // Update height and rebalance the tree
    root = avl_rebalance(root);
    return (root);
}
