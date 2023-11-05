#ifndef __DSL_STRING_H__
#define __DSL_STRING_H__

#include "types.h"

#define STRING_CASE_MASK 0x20 /* 0b00100000 */

public u32 strlen(const i8 *string);
public i32 strtoi32(const i8 *string);
public i8 *i32tostr(i32 num, i8 *buf, u32 size);

public void strupper(const i8 *source, i8 *out);
public void strlower(const i8 *source, i8 *out);

public bool isnum(const i8 val);
public bool ischr(const i8 val);
public bool strequal(const i8 *rhs, const i8 *lhs);

#endif /* __DSL_STRING_H__ */
