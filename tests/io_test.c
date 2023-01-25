#include "dsl/io.h"
#include "dsl/types.h"

i32 main(i32 argc, i8 **argv)
{
        __dsl_print("Hello, world!\n");

        i8 buffer[0x200];

        __dsl_print("Please insert your name: ");
        __dsl_read(STDIN_FD, buffer, 0x200);

        __dsl_print("Your name is: ");
        __dsl_print(buffer);
}

