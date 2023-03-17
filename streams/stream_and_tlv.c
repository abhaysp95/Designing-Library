#include "stream.h"
#include <string.h>

/* you'll sent this dat, say, through the socket. The data sent will be
 * stream->b, and size will be, stream->next */
void serialize_tlv() {
	ser_buff_t *stream;
	init_serialized_buffer(&stream);

	char data = 132;
	serialize_data(stream, &data, 1);

	data = 20;  /* size for ip-addr on tlv */
	serialize_data(stream, &data, 1);

	// ip: 14.1.1.1
	unsigned ip = (14 << 24) + (1 << 16) + (1 << 8) + 1;
	serialize_data(stream, (char*)&ip, 4);
	char mask = 24; // subnet mask
	serialize_data(stream, &mask, 1);

	// ip: 14.1.1.2
	ip = (14 << 24) + (1 << 16) + (1 << 8) + 2;
	serialize_data(stream, (char*)&ip, 4);
	mask = 24; // subnet mask
	serialize_data(stream, &mask, 1);

	// ip: 14.1.1.3
	ip = (14 << 24) + (1 << 16) + (1 << 8) + 3;
	serialize_data(stream, (char*)&ip, 4);
	mask = 24; // subnet mask
	serialize_data(stream, &mask, 1);

	// ip: 14.1.1.4
	ip = (14 << 24) + (1 << 16) + (1 << 8) + 4;
	serialize_data(stream, (char*)&ip, 4);
	mask = 24; // subnet mask
	serialize_data(stream, &mask, 1);

	// put mac address
	data = (char)222;
	serialize_data(stream, &data, 1);

	data = 12;  // size
	serialize_data(stream, &data, 1);

	char mac1[6] = {8, 0, 27, 0x3e, 97, 62};
	serialize_data(stream, (char*)&mac1, 6);

	char mac2[6] = {8, 0, 27, 0xce, 90, 78};
	serialize_data(stream, (char*)&mac2, 6);
}

/* on recieving side, when you'll recieve the tlv, you init the stream, and
 * you'll point the data recieved (say, via socket) by stream->buff, and the
 * initial next would be 0, (stream->size would be the size of data recieved, if
 * needed) */
void deserialize_tlv(char *dest, ser_buff_t *buff, int size) {
	// size is the data, read at a time. Generally, with tlv deserialization
	// it'll be the size of next block you want to read
	memcpy(dest, buff->b, size);
	buff->next += size;
}

int main(void) {
	/* unsigned dest;
	deserialize_tlv((char*)&dest, stream->b, 4); */
}
