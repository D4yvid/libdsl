#ifndef __DSL_TYPES_H__
#define __DSL_TYPES_H__

#define public			extern
#define internal		static

#define UNIQUE_PTR(v) __attribute__((annotate("unique ptr")) restrict v *

#ifndef NULL
#	define NULL ((void *) 0x00)
#endif

#ifndef null
#	define null ((void *) 0x00)
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
	#undef true
	#undef false
	#undef bool

	false   = 0,
	true    = 1
} bool;

#endif /* __DSL_TYPES_H__ */
