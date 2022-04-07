#ifndef TREE_H
#define TREE_H

typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *parent;
} tree_node_t;

typedef struct tree {
	tree_node_t *root;
} tree_t;

tree_t *init_tree(void);

tree_node_t *
init_tree_node(int n);

int
add_tree_node_by_value(tree_t *tree, int n);

/** pre-requisite functions to write iterative macros for a tree */
tree_node_t *
get_left_most(tree_node_t *node);

tree_node_t *
get_next_inorder_successor(tree_node_t *node);

#define ITERATE_BST_BEGIN(tree_ptr, current_node_ptr) { \
	tree_node_t *_next = NULL; \
	current_node_ptr = get_left_most(tree_ptr->root); \
	for (; current_node_ptr != NULL; current_node_ptr = _next) { \
		_next = get_next_inorder_successor(current_node_ptr);

#define ITERATE_BST_END }}

#endif
