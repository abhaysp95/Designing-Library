#include "linkedlist.h"

#include <stdlib.h>

int
main(int argc, char **argv) {
	ll_t *list = (ll_t *)calloc(1, sizeof(ll_t));

	ll_node_t *new_node = malloc_new_node((void *)10);
	ll_node_t *second_node = malloc_new_node((void *)20);

	// ll_node_t *third_node = (ll_node_t *)calloc(1, sizeof(ll_node_t));  // error

	linkedlist_insertion(list, new_node);
	linkedlist_insertion(list, second_node);
}
