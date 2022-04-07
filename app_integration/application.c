#include "dll.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/** application specific data structure */
typedef struct person_ {
	char name[32];
	int age;
	int weight;
} person_t;

static void
print_person_details(person_t *person) {
	printf("Name = %s\n", person->name);
	printf("Age = %d\n", person->age);
	printf("Weight = %d\n", person->weight);
	puts("------------------------");
}

static void
print_person_db(dll_t *person_db) {
	if (!person_db || !person_db->head) return;

	dll_node_t *head = person_db->head;
	person_t *data = NULL;

	while(head) {
		data = head->data;
		print_person_details(data);
		head = head->right;
	}
}

int main(int argc, char** argv) {
	person_t *person1 = (person_t *)calloc(1, sizeof(person_t));
	strncpy(person1->name, "James", strlen("James"));
	person1->age = 32;
	person1->weight = 60;
    person_t *person2 = (person_t *)calloc(1, sizeof(person_t));
    strncpy(person2->name, "Joseph", strlen("Joseph"));
    person2->age = 41;
    person2->weight = 70;
    person_t *person3 = (person_t *)calloc(1, sizeof(person_t));
    strncpy(person3->name, "Jack", strlen("Jack"));
    person3->age = 29;
    person3->weight = 55;

	dll_t *person_db = get_new_dll();
	add_data_to_dll(person_db, person1);
	add_data_to_dll(person_db, person2);
	add_data_to_dll(person_db, person3);

	print_person_db(person_db);

	remove_data_from_dll_by_data_ptr(person_db, person2);

	fputs("\n", stdout);

	print_person_db(person_db);

	printf("\nis dll empty ? : %s\n\n", is_dll_empty(person_db) == 0 ? "True" : "False");

	drain_dll(person_db);

	print_person_db(person_db);

	printf("\nis dll empty ? : %s\n\n", is_dll_empty(person_db) == 0 ? "True" : "False");

	return 0;
}
