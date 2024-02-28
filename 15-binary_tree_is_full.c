#include "binary_trees.h"

/**
 * is_full_recursively - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, otherwise 0
 */
int is_full_recursively(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
			(tree->left == NULL && tree->right != NULL) ||
			is_full_recursively(tree->left) == 0 ||
			is_full_recursively(tree->right) == 0)

			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursively(tree));
}
