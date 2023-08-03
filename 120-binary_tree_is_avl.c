#include "binary_trees.h"
#include "limits.h"
/**
 * measure_height - measures the height
 * @tree: pointer to the node
 *
 * Return: height
 */
size_t measure_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + measure_height(tree->left) : 1;
		right_height = tree->right ? 1 + measure_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
/**
 * check_avl_properties - checks the avl properties
 * @tree: pointer to the node
 * @min_value: minimum value
 * @max_value: maximum value
 *
 * Return: height
 */
int check_avl_properties(const binary_tree_t *tree,
		int min_value, int max_value)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		if (tree->n < min_value || tree->n > max_value)
			return (0);
		left_height = measure_height(tree->left);
		right_height = measure_height(tree->right);
		height_diff = (left_height > right_height) ? left_height
			- right_height : right_height - left_height;
		if (height_diff > 1)
			return (0);
		return ((check_avl_properties(tree->left, min_value, tree->n - 1)
					&& check_avl_properties(tree->right, tree->n + 1, max_value)));
	}
	return (1);
}
/**
 * binary_tree_is_avl - checks if it an avl
 * @tree: pointer to the node
 *
 * Return: 1
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_avl_properties(tree, INT_MIN, INT_MAX));
}
