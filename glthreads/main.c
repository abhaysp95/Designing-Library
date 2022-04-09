#include "glthread.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp_ {
	char name[32];
	unsigned int salary;
	char designation[32];
	unsigned int emp_id;
	glthread_node_t glnode;
} emp_t;

void
print_emp_details(emp_t *emp) {
	printf("Name: %s\n", emp->name);
	printf("Salary: %u\n", emp->salary);
	printf("Designation: %s\n", emp->designation);
	printf("Emp id: %u\n", emp->emp_id);
	printf("\n");
}

int
main(int argc, char **argv) {

	emp_t *emp1 = (emp_t *)calloc(1, sizeof(emp_t));
	strncpy(emp1->name, "Neha", strlen("Neha"));
	emp1->salary = 50000;
	strncpy(emp1->designation, "HR", strlen("HR"));
	emp1->emp_id = 21;
	GLTHREAD_NODE_INIT((&emp1->glnode));

    emp_t *emp2  = calloc(1, sizeof(emp_t));
    strncpy(emp2->name, "Abhishek", strlen("Abhishek"));
    emp1->salary = 150000;
    strncpy(emp2->designation, "SE3", strlen("SE3"));
    emp2->emp_id = 32;
    GLTHREAD_NODE_INIT((&emp2->glnode));

    emp_t *emp3  = calloc(1, sizeof(emp_t));
    strncpy(emp3->name, "Arun", strlen("Arun"));
    emp3->salary = 60000;
    strncpy(emp3->designation, "SE4", strlen("SE4"));
    emp3->emp_id = 27;
    GLTHREAD_NODE_INIT((&emp3->glnode));

	/** now create a dll, glthread */
	glthread_t *emp_list = (glthread_t *)calloc(1, sizeof(glthread_t));
	init_glthread(emp_list, OFFSETOF(emp_t, glnode));

	/** add glnode to glthread (list) */
	glthread_add(emp_list, &emp1->glnode);
	glthread_add(emp_list, &emp2->glnode);
	glthread_add(emp_list, &emp3->glnode);

	/** walk over glthread */
	emp_t *emp = NULL;
	ITERATE_GLTHREAD_BEGIN(emp_list, emp_t, emp)
		print_emp_details(emp);
	ITERATE_GLTHREAD_END

	return 0;
}
