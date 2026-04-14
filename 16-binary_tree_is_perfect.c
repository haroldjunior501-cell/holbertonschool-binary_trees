#include "binary_trees.h"

/**
 * tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of the node
 */
static size_t tree_depth(const binary_tree_t *tree)
{
	if (tree->parent == NULL)
		return (0);

	return (tree_depth(tree->parent) + 1);
}

/**
 * perfect_check - checks if all leaves are at the same depth
 * @tree: pointer to the current node
 * @depth: expected depth for leaves
 *
 * Return: 1 if the subtree is perfect, otherwise 0
 */
static int perfect_check(const binary_tree_t *tree, size_t depth)
{
	if (tree->left == NULL && tree->right == NULL)
		return (tree_depth(tree) == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, depth) &&
		perfect_check(tree->right, depth));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;
	const binary_tree_t *leaf;

	if (tree == NULL)
		return (0);

	leaf = tree;
	while (leaf->left != NULL)
		leaf = leaf->left;

	depth = tree_depth(leaf);

	return (perfect_check(tree, depth));
}
