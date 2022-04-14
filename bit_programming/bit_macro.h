#ifndef BIT_MACRO_H
#define BIT_MACRO_H

#define SET_BIT(n, BITF) \
	(n |= (1<<BITF))

// 1<<n means that nth bit will be set or unset, but just n means that n number
// will set, meaning n = 3, "0011" will be set

#define UNSET_BIT(n, BITF) \
	(n &= (~(1<<BITF)))

#define IS_BIT_SET(n, BITF) \
	(n & (1<<BITF))

#define TOGGLE(n, BITF) \
	(n ^= (1<<(BITF-1)))

#define COMPLEMENT16(n) \
	(n ^ 0xFFFF)

#define COMPLEMENT(n) \
	(~n)

typedef enum col_ {
	RED = 1<<0,
	GREEN = 1<<1,
	YELLOW = 1<<2,
	BLUE = 1<<3,
	MAX_COL = 1<<4,
} col_t;

#define PRINT_BITS(x) { \
	int n = sizeof(x) * 8 - 1; \
	for (int i = n; i >= 0; i--) { \
		printf("%d", IS_BIT_SET(x, 1<<i) ? 1 : 0); \
	} \
	printf("\n"); \
}

#define COUNT_BITS_SET(x, c) { \
	c = 0; \
	int n = sizeof(x) * 8 - 1; \
	for (int i = n; i >= 0; i--) { \
		c = IS_BIT_SET(x, 1<<i) ? c + 1 : c; \
	} \
}

#endif
