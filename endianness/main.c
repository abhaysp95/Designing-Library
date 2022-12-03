#include <stdio.h>

// to confirm, I need one Big-endian machine

int main(void) {
	unsigned int a = 1025;  // 2 bytes
	char ist_byte = *((char *)&a);
	if (2 == ist_byte) {
		printf("Big endian\n");
	} else { // if ist_byte == 1
		printf("little endian\n");
	}

	return 0;
}
