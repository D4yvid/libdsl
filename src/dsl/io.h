#ifndef __DSL_IO_H__
#define __DSL_IO_H__

#include "types.h"

#define STDIN_FD  0x00
#define STDOUT_FD 0x01
#define STDERR_FD 0x02

public void print(const i8 *buffer);
public void printf(const i8 *fmt, ...);
public u32 write(u32 fd, const i8 *buffer, u32 size);
public u32 read(u32 fd, i8 *buffer, u32 count);

#endif /* __DSL_IO_H__ */
