#ifndef UTIL_H
#define UTIL_H

#define offset(struct_name, field_name) \
	(uintptr_t)&((struct_name *)0)->field_name

#define GLTHREAD_TO_OBJECT(fn_name, struct_name, field_name) \
	static inline struct_name *fn_name(glthread_node_t *glnode) { \
		return (struct_name *)((void *)glnode - offset(struct_name, field_name)); \
	}


typedef struct glthread_node_ {
	/** implementaion not necessary */
} glthread_node_t;

typedef struct emp_ {
	char name[30];
	unsigned int salary;
	char designation[30];
	unsigned int emp_id;
	glthread_node_t glnode;
} emp_t ;

#endif
