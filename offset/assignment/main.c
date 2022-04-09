#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "util.h"

emp_t *employee;

/** Solution: 1 */
/** signature provided to work on (can't change) */
void print_emp_details(glthread_node_t* glnode);
void print_employee_info(emp_t *emp);

int main(int argc, char **argv) {
	employee = (emp_t *)calloc(1, sizeof(emp_t));

	strncpy(employee->name, "somename", strlen("somename"));
	employee->salary = 100000;
	strncpy(employee->designation, "manager", strlen("manager"));
	employee->emp_id = 10;

	print_emp_details(&employee->glnode);

	return 0;
}

/** Solution: 2 */
GLTHREAD_TO_OBJECT(glnode_to_employee, emp_t, glnode)

void
print_emp_details(glthread_node_t *glnode) {
	// print_employee_info((emp_t*)((void*)glnode - offset(emp_t, glnode))); // --> with Solution 1
	print_employee_info(glnode_to_employee(glnode));  // --> with solution 2
}


void
print_employee_info(emp_t *emp){
	printf("Employee name = %s\n", emp->name);
	printf("salary = %u\n", emp->salary);
	printf("designation = %s\n", emp->designation);
	printf("emp_id = %u\n", emp->emp_id);
}


/** print_emp_details using glnode only (don't access employee directly) */
/* void  // wrote this when I didn't knew print_employee_info() existed (see above for updated approach)
print_emp_details(glthread_node_t *glnode) {
	unsigned int glnode_offset = offset(emp_t, glnode);
	void *start_ptr = (void *)glnode - glnode_offset;
	printf("name: %s\n", (char *)(start_ptr));
	printf("salary: %u\n", *(unsigned int*)(start_ptr + offset(emp_t, salary)));
	printf("designation: %s\n", (char *)(start_ptr + offset(emp_t, designation)));
	printf("emp_id: %u\n", *(unsigned int*)(start_ptr + offset(emp_t, emp_id)));
}*/
