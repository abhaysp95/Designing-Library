#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/** opaque pointers are pointers to opaque objects
 * opaque object means that the attributes for a object are hidden to the
 * library itself and not exposed to be used by the application independently
 */

typedef struct ll_node_ ll_node_t;

typedef struct ll_ {
	ll_node_t *head;
} ll_t;

void
linkedlist_insertion(ll_t *lst, ll_node_t *node);

ll_node_t *
malloc_new_node(void *data);

#endif
