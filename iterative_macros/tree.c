#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/** TODO:
 * add pre-order and post-order traversal too
 * maybe add callback for traversal with tree_t
 * search for threaded binary tree to improve performance of iterative macro
 * for bst
 */

tree_t *
init_tree() {
	tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));
	if (!tree) return NULL;
	tree->root = NULL;
	return tree;
}

tree_node_t *
init_tree_node(int n) {
	tree_node_t *node_ptr = (tree_node_t *)calloc(1, sizeof(tree_node_t));
	if (!node_ptr) return NULL;

	node_ptr->data = n;
	node_ptr->left = NULL;
	node_ptr->right = NULL;
	node_ptr->parent = NULL;
	return node_ptr;
}

int
add_tree_node_by_value(tree_t *tree, int n) {
	if (!tree) return -1;

	tree_node_t *node_ptr = init_tree_node(n);

	if (!tree->root) {
		tree->root = node_ptr;
		return 0;
	}

	tree_node_t *parent = NULL, *root = tree->root;
	while (root) {
		parent = root;
		root = (n <= root->data) ? root->left : root->right;
	}


	if (n <= parent->data)
		parent->left = node_ptr;
	else
		parent->right = node_ptr;
	node_ptr->parent = parent;

	return 0;
}

tree_node_t *
get_left_most(tree_node_t *node) {
	if (!node || !node->left) return NULL;

	while (node->left)
		node = node->left;
	return node;
}

tree_node_t *
get_next_inorder_successor(tree_node_t *node) {
	if (!node) return NULL;

	/** if node is root node */
	if (!node->parent) {
		// maybe node->left is also needed to be handled
		if (node->right) {
			if (node->right->left)
				return get_left_most(node->right);
			else
				return node->right;
		}
		return NULL;
	}

	/** if node is the left child of parent */
	if (node == node->parent->left) {
		if (!node->right)
			return node->parent;
		else {
			if (node->right->left)
				return get_left_most(node->right);
			else
				return node->right;
		}
	}

	/** if node is the right child of parent */
	if (node == node->parent->right) {
		if (node->right) {
			if (node->right->left)
				return get_left_most(node->right);
			else
				return node->right;
		}
	}

	/** inorder successor of node is an ancestor whose left child is also an
	 * ancestor */
	tree_node_t *grand_parent = node->parent->parent;
	tree_node_t *parent = node->parent;

	while (grand_parent && parent != grand_parent->left) {
		parent = grand_parent;
		grand_parent = grand_parent->parent;
	}

	return grand_parent;
}

int main(int argc, char **argv) {
	tree_t *tree = init_tree();

	add_tree_node_by_value(tree, 100);
    add_tree_node_by_value(tree,  50);
    add_tree_node_by_value(tree,  10);
    add_tree_node_by_value(tree,  90);
    add_tree_node_by_value(tree,  95);
    add_tree_node_by_value(tree,  99);

	tree_node_t *node_ptr = NULL;
	ITERATE_BST_BEGIN(tree, node_ptr)
		printf("%d ", node_ptr->data);
	ITERATE_BST_END
	printf("\n");

	return 0;
}
