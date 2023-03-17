#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stream.h"

/* int main(void) {
	ser_buff_t *stream;
	init_serialized_buffer(&stream);
	char *data = "this is data";
	serialize_data(stream, data, strlen(data));
} */

void serialize_data(ser_buff_t *buff, char *data, unsigned nbytes) {
	unsigned available_size = buff->size - buff->next;
	bool needs_resize = false;

	if (available_size < nbytes) {
		buff->size *= 2;
		available_size = buff->size - buff->next;
		needs_resize = true;
	}

	if (!needs_resize) {
		memcpy(buff->b + buff->next, data, nbytes);
		buff->next += nbytes;
		return;
	}

	buff->b = realloc(buff->b, buff->size);
	memcpy(buff->b + buff->next, data, nbytes);
	buff->next += nbytes;
}

void init_serialized_buffer(ser_buff_t **b) {
	*b = (ser_buff_t *)malloc( 1 * sizeof(ser_buff_t) );
	(*b)->b = (char *)malloc(SERIALIZED_BUFFER_DEFAULT_SIZE * sizeof(char));
	(*b)->size = SERIALIZED_BUFFER_DEFAULT_SIZE;
	(*b)->next = 0;
}
