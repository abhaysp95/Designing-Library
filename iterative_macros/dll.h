/** header file for doubly linked list */

typedef struct dll_node_ {
	void* data;
	struct dll_node_ *left;
	struct dll_node_ *right;
} dll_node_t;

typedef struct dll_ {
	dll_node_t *head;
	int (*key_match)(void *, void *);
	int (*comparison_fn)(void *, void *);
} dll_t;

void
register_key_match_callback(dll_t *dll, int (*key_match)(void *, void *));

void
register_comparison_callback(dll_t *dll, int (*comparison_fn)(void *, void *));

/** generic search function */
void *
dll_search_by_key(dll_t *dll, void *key);

int
dll_priority_insert_data(dll_t *dll, void *data);

/** public function to create and return a new empty doubly linked list */
dll_t *
get_new_dll();

/** public function declaration to add the application data to dll */
int
add_data_to_dll(dll_t *dll, void *appn_data);

int /** 0 on success, -1 on fail */
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data);

int  /** 0 if empty, -1 if not empty */
is_dll_empty (dll_t *dll);

void  /** delete all nodes from a dll, but do not free appln data */
drain_dll(dll_t *dll);

/** Iterative macro (iteratos over this dll) */
#define ITERATE_LIST_BEGIN(list_ptr, node_ptr) { \
	dll_node_t *_node_ptr = NULL; \
	node_ptr = list_ptr->head; \
	for (; node_ptr != NULL; node_ptr = _node_ptr) { \
		if (!node_ptr) break; \
		_node_ptr = node_ptr->right;

#define ITERATE_LIST_END }}
