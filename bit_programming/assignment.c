#include <stdio.h>
#include <stdint.h>

#include "bit_macro.h"

int
main(int argc, char **argv) {
	uint32_t num = 40;
	SET_BIT(num, 2);
	PRINT_BITS(num);
	UNSET_BIT(num, 2);
	PRINT_BITS(num);
	unsigned int c = 0;
	COUNT_BITS_SET(num, c);
	printf("bits set count: %u\n", c);
	return 0;
}
