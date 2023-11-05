#include "dsl/io.h"
#include "dsl/types.h"

i32 main(i32 argc, i8 **argv)
{
	print("Hello, world!\n");

	i8 buffer[0x200];

	print("Please insert your name: ");
	read(STDIN_FD, buffer, 0x200);

	print("Your name is: ");
	print(buffer);
}
