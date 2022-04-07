/** header file for doubly linked list */

typedef struct dll_node_ {
	void* data;
	struct dll_node_ *left;
	struct dll_node_ *right;
} dll_node_t;

typedef struct dll_ {
	dll_node_t *head;
} dll_t;

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
