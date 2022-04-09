#include <stdio.h>
#include <stdint.h>

typedef struct emp_ {
	char name[32];
	unsigned int salary;
	char designation[32];
	unsigned int emp_id;
} emp_t;

#define offset(struct_name, field_name) \
	(uintptr_t)&((struct_name *)0)->field_name

/** -> comes above & in operator precedence */

int main(int argc, char **argv) {
	int name_offset = offset(emp_t, name);
	int salary_offset = offset(emp_t, salary);
	int designation_offset = offset(emp_t, designation);
	int emp_id_offset = offset(emp_t, emp_id);
	printf("%d\n", name_offset);
	printf("%d\n", salary_offset);
	printf("%d\n", designation_offset);
	printf("%d\n", emp_id_offset);
	return 0;
}
