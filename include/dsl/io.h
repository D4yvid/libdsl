#ifndef __DSL_IO_H__
#define __DSL_IO_H__

#include "dsl/types.h"

#define STDIN_FD  0x00
#define STDOUT_FD 0x01
#define STDERR_FD 0x02


__DSL_API__
void __dsl_print(const i8 *buffer);

__DSL_API__
void __dsl_printf(const i8 *fmt, ...);

__DSL_API__
u32 __dsl_write(u32 fd, const i8 *buffer, u32 size);

__DSL_API__
u32 __dsl_read(u32 fd, i8 *buffer, u32 count);

#endif /* __DSL_IO_H__ */
