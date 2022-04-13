#ifndef BIT_MACRO_H
#define BIT_MACRO_H

#define SET_BIT(n, BITF) \
	(n |= BITF)

#define UNSET_BIT(n, BITF) \
	(n &= (~BITF))

#define IS_BIT_SET(n, BITF) \
	(n & BITF)

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

#endif
