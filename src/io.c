#include "dsl/io.h"
#include "dsl/string.h"
#include "dsl/syscall.h"
#include "dsl/types.h"

void print(const i8 *buffer)
{
	u32 size = strlen(buffer);
	u32 fd   = STDOUT_FD;

	write(fd, buffer, size);
}

u32 write(u32 fd, const i8 *buffer, u32 size)
{
	u32 written = 0x00000000;

	__SYSCALL_WRITE(written, fd, buffer, size);

	return written;
}

u32 read(u32 fd, i8 *buffer, u32 count)
{
	u32 bytes_read = 0x00000000;

	__SYSCALL_READ(bytes_read, fd, buffer, count);

	return bytes_read;
}

void printf(const i8 *fmt, ...)
{
	i32 i = 0;

	while (*fmt)
	{
		i = 1;

		switch (*fmt)
		{
		case '%':
			break;
		}

		fmt += i;
	}
}
