#ifndef __STREAM_H__
#define __STREAM_H__

#define SERIALIZED_BUFFER_DEFAULT_SIZE 100

typedef struct serialized_buffer {
	char *b;  // pointer to buffer
	int size;  // size of buffer
	int next;  // points to end of data in buffer (<= size)
} ser_buff_t;

void init_serialized_buffer(ser_buff_t **b);
void serialize_data(ser_buff_t *b, char *data, unsigned nbytes);

#endif
