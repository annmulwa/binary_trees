#include "binary_trees.h"

unsigned char is_leaf_of_binary(const binary_tree_t *node);
size_t depth_of_node(const binary_tree_t *tree);
const binary_tree_t *get_leaf_of_binary(const binary_tree_t *tree);
int is_perfect_recursively(const binary_tree_t *tree,
		size_t leaf_depth, size_t node_level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf_of_binary - Checks if a node is a leaf of a binary tree
 * @node: pointer to the node to check
 * Return: 1 if true, else, 0.
 */
unsigned char is_leaf_of_binary(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth_of_node - Returns the depth of a given
 *         node in a binary tree.
 * @tree: pointer to the node to measure the depth of
 * Return: depth of node
 */
size_t depth_of_node(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth_of_node(tree->parent) : 0);
}

/**
 * get_leaf_of_binary - Returns the leaf of a binary tree.
 * @tree: pointer to the root node of the tree to find a leaf in
 * Return: pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf_of_binary(const binary_tree_t *tree)
{
	if (is_leaf_of_binary(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf_of_binary(tree->left) :
		get_leaf_of_binary(tree->right));
}

/**
 * is_perfect_recursively - Checks if a binary tree is perfect recursively.
 * @tree: pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @node_level: level of current node.
 * Return: 1 if the tree is perfect,otherwise 0.
 */
int is_perfect_recursively(const binary_tree_t *tree,
		size_t leaf_depth, size_t node_level)
{
	if (is_leaf_of_binary(tree))
		return (node_level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursively(tree->left, leaf_depth, node_level + 1) &&
		is_perfect_recursively(tree->right, leaf_depth, node_level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursively(tree,
		depth_of_node(get_leaf_of_binary(tree)), 0));
}
