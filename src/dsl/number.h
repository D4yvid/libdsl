#ifndef __DSL_NUMBER_H__
#define __DSL_NUMBER_H__

#include "types.h"

public i32 get_digit_count(i32 number);

inline i32 max(i32 a, i32 b) {
	return a > b ? a : b;
}

inline i32 min(i32 a, i32 b) {
	return a < b ? a : b;
}

#endif /** __DSL_NUMBER_H__ */
