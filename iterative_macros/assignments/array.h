#ifndef ARRAY_H
#define ARRAY_H

/* #define ITERATE_ARRAY_BEGIN(arrptr, array_size, start_index, scansize, out_index) { \
	if (arrptr != NULL && start_index >= 0) { \
		int c = 0; \
		for (;c < scansize; c++) { \
			out_index = c + start_index; \
			if (out_index >= array_size) \
				out_index -= array_size; */

// second approach
#define ITERATE_ARRAY_BEGIN(arrptr, array_size, start_index, scansize, out_index) { \
	unsigned int _i = 0, next = 0; \
	out_index = start_index; \
	for (; _i < scansize; _i++, out_index = next) { \
		if (out_index == array_size - 1) \
			next = 0; \
		else \
			next = out_index + 1;


#define ITERATE_ARRAY_END }}}

#endif
