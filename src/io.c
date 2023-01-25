#include "dsl/io.h"
#include "dsl/string.h"
#include "dsl/syscall.h"
#include "dsl/types.h"
#include <stdarg.h>

void __dsl_print(const i8 *buffer)
{
        u32 size = __dsl_strlen(buffer);
        u32 fd   = STDOUT_FD;

        __dsl_write(fd, buffer, size);
}

u32 __dsl_write(u32 fd, const i8 *buffer, u32 size)
{
        u32 written = 0x00000000;

        __SYSCALL_WRITE(written, fd, buffer, size);

        return written;
}

u32 __dsl_read(u32 fd, i8 *buffer, u32 count)
{
        u32 bytes_read = 0x00000000;

        __SYSCALL_READ(bytes_read, fd, buffer, count);

        return bytes_read;
}

void __dsl_printf(const i8 *fmt, ...)
{

}
