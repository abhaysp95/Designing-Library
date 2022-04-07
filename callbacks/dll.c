#include "dll.h"
#include <stdlib.h>

/** public function to create and return a new empty doubly linked list */
dll_t*
get_new_dll() {
	dll_t *dll = (dll_t *)calloc(1, sizeof(dll_t));
	dll->head = NULL;
	return dll;
}

/** public function declaration to add the application data to dll */
int
add_data_to_dll(dll_t *dll, void *appn_data) {
	if(!dll || !appn_data) return -1;
	dll_node_t *dll_new_node = (dll_node_t *)calloc(1, sizeof(dll_node_t));
	dll_new_node->data = appn_data;
	dll_new_node->left = NULL;
	dll_new_node->right = NULL;

	/** if this is the first node */
	if(!dll->head) {
		dll->head = dll_new_node;
		return 0;
	}

	/** adding node at very first of dll (if dll exists) */
	dll_node_t *cur_first_node = dll->head;
	dll_new_node->right = cur_first_node;
	cur_first_node->left = dll_new_node;
	dll->head = dll_new_node;
	return 0;
}

void
register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *)) {
	dll->key_match = key_match;
}

void *
dll_search_by_key(dll_t *dll, void *key) {
	if (!dll || !dll->head) return NULL;

	dll_node_t *head = dll->head;

	while (head) {
		if (dll->key_match(head->data, key) == 0)
			return (void *)head->data;
		head = head->right;
	}

	return NULL;
}

void
register_comparison_callback(dll_t *dll, int (*comparison_fn)(void *, void *)) {
	dll->comparison_fn = comparison_fn;
}

/** return 0 on success, -1 on failure */
int
dll_priority_insert_data(dll_t *dll, void *data) {

	if (!dll) return -1;

	if (!dll->head) {
		add_data_to_dll(dll, data);

		return 0;
	}

	dll_node_t *data_node = (dll_node_t *)calloc(1, sizeof(dll_node_t));
	data_node->data = data;
	data_node->left = NULL;
	data_node->right = NULL;

	/** if there's only one node */
	if (dll->head && !dll->head->right) {
		if (dll->comparison_fn(data, dll->head->data) == -1) {
			dll->head->left = data_node;
			data_node->right = dll->head;
			dll->head = data_node;
		} else {
			dll->head->right = data_node;
			data_node->left = dll->head;
		}

		return 0;
	}

	/** if there's more than one node */
	dll_node_t *curr = dll->head;
	dll_node_t *prev = NULL;

	while (curr) {
		if (dll->comparison_fn(data, curr->data) == 1) {
			prev = curr;
			curr = curr->right;
			continue;
		}
		prev->right = data_node;
		curr->left = data_node;
		data_node->left = prev;
		data_node->right = curr;

		return 0;
	}

	/** if reached to last node */
	prev->right = data_node;
	data_node->left = prev;

	return 0;
}
