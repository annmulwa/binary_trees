#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of the node
 * @node: nodeto find a sibling
 *
 * Return: pointer to sibling node
 **/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (node->parent->left == node) ? node->parent->right : node->parent->left;
}
