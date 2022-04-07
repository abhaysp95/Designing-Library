#include "dll.h"
#include <memory.h>
#include <stdlib.h>

int /** 0 on success, -1 on fail */
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data)
{
	// approach considers that you provided head as the start of dll
	// and it only checks to right of head
	dll_node_t *ptr = dll->head;
	if (ptr == NULL) return -1;  // empty dll

	while (ptr != NULL)
	{
		if (ptr->data == data)
		{
			if (ptr->left == NULL)  /** head node is match */
			{
				ptr->right->left = ptr->left;
				break;
			}
			else if (ptr->right == NULL)  /** last node is match */
			{
				ptr->left->right = ptr->right;
				break;
			}
			else
			{
				ptr->left->right = ptr->right;
				ptr->right->left = ptr->left;
				break;
			}
		}
		ptr = ptr->right;
	}
	return 0;
}

int  /** 0 if empty, -1 if not empty */
is_dll_empty (dll_t *dll)
{
	return dll->head == NULL ? 0 : -1;
}

void  /** delete all nodes from a dll, but do not free appln data */
drain_dll(dll_t *dll)
{
	if (dll->head == NULL) return;

	dll_node_t *ptr = dll->head;
	dll_node_t *pptr = ptr;
	while (ptr != NULL)
	{
		pptr = ptr;
		ptr = ptr->right;
		free(pptr);
	}

	dll->head = NULL;
}
