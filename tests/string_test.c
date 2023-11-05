#include "dsl/io.h"
#include "dsl/string.h"
#include <assert.h>

i32 main(i32 argc, i8 **argv)
{
	i8 tmpbuf[32];

	assert(-12345 == strtoi32("-12345"));
	assert(123456 == strtoi32("123456"));

	assert(10 == strlen("0123456789"));
	assert(16 == strlen("0123456789ABCDEF"));

	i32tostr(32, tmpbuf, 32);

	return 0;
}
