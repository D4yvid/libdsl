#ifndef __DSL_TYPES_H__
#define __DSL_TYPES_H__

#define __DSL_API__             extern
#define __DSL_PRIV_API__        static
#define __dsl_unique_ptr__(v) v *

#ifndef NULL
#       define NULL ((void *) 0x00)
#endif

typedef char		i8;
typedef short		i16;
typedef int		i32;
typedef long		i64;

typedef unsigned char	u8;
typedef unsigned short	u16;
typedef unsigned int	u32;
typedef unsigned long	u64;

typedef enum
{
        false   = 0,
        true    = 1
} bool;

#endif /* __DSL_TYPES_H__ */
