#include <stdio.h>
#include <stdint.h>

#include "bit_macro.h"

int
main(int argc, char **argv)
{
	uint16_t num = 335;
	if (IS_BIT_SET(num, 2)) {  // 2nd bit pos from lsb
		printf("unsetting bit\n");
		UNSET_BIT(num, 2);
	} else {
		printf("setting bit\n");
		SET_BIT(num, 2);
	}
	printf("num: %u\n", num);

	printf("complement: %u\n", COMPLEMENT(num));
	printf("complement16: %u\n", COMPLEMENT16(num));

	printf("Toggle 4th: %u\n", TOGGLE(num, 4));
	printf("Toggle 4th: %u\n", TOGGLE(num, 4));

	uint8_t col_v = RED | YELLOW | BLUE;
	if (col_v & YELLOW) {
		printf("col_v contains yellow\n");
	}

	/** NOTE:
	 * Don't use enum "col_t" for initializing array with size, as 1<<4 is not
	 * 4 but 16
	 */
}
