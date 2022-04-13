#include "linkedlist.h"

#include <stdlib.h>

typedef struct ll_node_ {
	void *data;
	struct ll_node_ *left;
	struct ll_node_ *right;
} ll_node_t;

ll_node_t *
malloc_new_node(void *data) {
	ll_node_t *node = (ll_node_t *)calloc(1, sizeof(ll_node_t));
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return node;
}

static void
_add_next_node(ll_node_t *curr_node, ll_node_t *new_node) {
	if (!new_node->right) {
		new_node->right = curr_node;
		curr_node->left = new_node;
		return;
	}

	ll_node_t *neigh = new_node->right;
	new_node->right = curr_node;
	curr_node->left = new_node;
	curr_node->right = neigh;
	neigh->left = curr_node;
}

void
linkedlist_insertion(ll_t *lst, ll_node_t *node) {
	if (!lst) return;  // there's no list

	if (!lst->head) {
		lst->head = node;
		return;
	}

	ll_node_t *head = lst->head;
	_add_next_node(head, node);
	lst->head = node;
}
