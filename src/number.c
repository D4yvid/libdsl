#include "dsl/number.h"

i32 get_digit_count(i32 number)
{
	i32 count = 0;

	while (number > 0) {
		count++;

		number /= 10;
	}

	return count;
}

