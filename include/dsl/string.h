#ifndef __DSL_STRING_H__
#define __DSL_STRING_H__

#include "dsl/types.h"

#define STRING_CASE_MASK 0x20 /* 0b00100000 */

__DSL_API__
u32 __dsl_strlen(const i8 *string);

__DSL_API__
void __dsl_strupper(const i8 *source, i8 *out);

__DSL_API__
void __dsl_strlower(const i8 *source, i8 *out);

__DSL_API__
i32 __dsl_strtoi32(const i8 *string);

__DSL_API__
bool __dsl_isnum(const i8 val);

__DSL_API__
bool __dsl_ischr(const i8 val);

__DSL_API__
bool __dsl_strequal(const i8 *rhs, const i8 *lhs);

#endif /* __DSL_STRING_H__ */
