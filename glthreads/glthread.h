#ifndef GLTHREAD_H
#define GLTHREAD_H

#include <stdint.h>

typedef struct glthread_node_ {
	struct glthread_node_ *left;
	struct glthread_node_ *right;
} glthread_node_t;

typedef struct glthread_ {
	glthread_node_t *head;
	uintptr_t offset;
} glthread_t;

#define OFFSETOF(struct_name, field_name) \
	(uintptr_t)&((struct_name *)0)->field_name

#define GLTHREAD_NODE_INIT(glnode) \
	glnode->left = NULL; \
	glnode->right = NULL;

#define ITERATE_GLTHREAD_BEGIN(lst_ptr, struct_type, ptr) { \
	glthread_node_t *_glnode = NULL, *_next = NULL; \
	for (_glnode = lst_ptr->head; _glnode; _glnode = _next) { \
		_next = _glnode->right; \
		ptr = (struct_type *)((char *)_glnode - lst_ptr->offset);

#define ITERATE_GLTHREAD_END }}

void
init_glthread(glthread_t *glthread, uintptr_t offset);

void
glthread_add(glthread_t *lst, glthread_node_t *glnode);

void
glthread_remove(glthread_t *lst, glthread_node_t *glnode);

#endif
