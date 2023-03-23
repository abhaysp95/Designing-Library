#include "serialize.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_serialized_buffer(ser_buff_t **b) {
	(*b) = (ser_buff_t *)malloc(sizeof(ser_buff_t));
	(*b)->b = (char *)malloc(sizeof(char) * SERIALIZE_BUFFER_DEFAULT_SIZE);
	(*b)->size = SERIALIZE_BUFFER_DEFAULT_SIZE;
	(*b)->next = 0;
	(*b)->checkpoint = 0;  // TODO: no idea what's checkpoint ?
}

void init_serialized_buffer_size(ser_buff_t **b, int size) {
	(*b) = (ser_buff_t *)malloc(sizeof(ser_buff_t));
	(*b)->b = (char *)malloc(sizeof(char) * size);
	(*b)->size = size;
	(*b)->next = 0;
	(*b)->checkpoint = 0;  // TODO: no idea what's checkpoint ?
}

void serialize_string(ser_buff_t *b, char *data, int size) {

	if (b->size - b->next < size) {
		b->size = 2 * b->size;
		b->b = realloc(b->b, b->size);
	}
	memcpy(b->b + b->next, data, size);
	b->next += size;
}

/* returns 0 if buffer is empty, else 1 */
int is_serialized_buffer_empty(ser_buff_t *b) {
	return  0 == b->size ? 0 : 1;
}

void deserialize_string(char *dest, ser_buff_t *b, int size) {
	if (b->next < size) {
		perror("buffer is smaller than the size to read");
	}

	memcpy(dest, b->b, size);

	// I'm not sure if this'll work though
	b->b = realloc(b->b + size, b->next - size);
}

void copy_in_serialized_buffer_by_offset(ser_buff_t *b, int size, char *value, int offset) {
	if (offset + size > b->size) {
		perror("buffer size is smaller than 'offset + size'");
	}

	memcpy(b->b + offset, value, size);
	// not making changes in b->size & b->next (as said in instructions)
}

void mark_checkpoint_serialize_buffer(ser_buff_t *b) {
	b->checkpoint = b->next;
}

int get_serialize_buffer_checkpoint_offset(ser_buff_t *b) {
	return b->checkpoint;
}

void serialize_buffer_skip(ser_buff_t *b, int skip_size) {
	if (skip_size < 0) {  // go reverse
		// skip_size = (skip_size * 2) + skip_size;  // get size in +ve digits

		if (b->next - skip_size < 0) {
			fprintf(stderr, "Can't set buffer offset to -%d", skip_size);
			return;
		}
		b->next -= skip_size;
	} else {
		if (b->next + skip_size > b->size) {
			// resize
			b->size *= 2;
			b->b = realloc(b->b, b->size);
		}
		b->next += skip_size;
	}
}

void free_serialize_buffer(ser_buff_t *b) {
	if (b->b != NULL) {
		free(b->b);
	}
	free(b);  // also freeing the data_structure
}
