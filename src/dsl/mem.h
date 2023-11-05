#ifndef __DSL_MEM_H__
#define __DSL_MEM_H__

#include "types.h"

#define __DSL_HEAP_ALIGNMENT 32

union heap_block_info
{
	u8 val;

	u8 free: 1;
	u8 size: 7;
};

public void memcpy(void *dest, void *src, u64 size);
public bool memcmp(void *rhs, void *lhs, u64 size);
public void *alloc(u64 size);
public void free(void *ptr);

#endif /* __DSL_MEM_H__ */
