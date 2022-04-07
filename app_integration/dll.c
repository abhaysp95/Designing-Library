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
