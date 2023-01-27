#include "dsl/string.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, i8 **argv)
{
        assert(strlen("Hello") == __dsl_strlen("Hello"));
        assert((strcmp("Hello", "Hello") == 0) == (__dsl_strequal("Hello", "Hello")));

        i8 out[6];

        __dsl_strupper("Hello", out);
        assert(__dsl_strequal(out, "HELLO"));

        __dsl_strlower("HELLO", out);

        assert(__dsl_strequal(out, "hello"));

        assert(-123214 == __dsl_strtoi32("-123214"));
        assert(12324123 == __dsl_strtoi32("12324123"));
}
