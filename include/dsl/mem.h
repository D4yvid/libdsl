#ifndef __DSL_MEM_H__
#define __DSL_MEM_H__

#include "types.h"

#define __DSL_HEAP_ALIGNMENT 32

union __dsl_heap_block_info
{
        u64 val;
        struct
        {
                u64 size: 63;
                u8 free: 1;
        };
};

struct __dsl_heap_block
{
        union __dsl_heap_block_info info;

        void *data;

        u64 size;
};

struct __dsl_free_block
{
        union __dsl_heap_block_info info;

        void *next, *prev;

        u64 size;
};

__DSL_API__
void __dsl_memcpy(void *dest, void *src, u64 size);

__DSL_API__
bool __dsl_memcmp(void *rhs, void *lhs, u64 size);

__DSL_API__
void *__dsl_alloc(u64 size);

__DSL_API__
void __dsl_free(void *ptr);

#endif /* __DSL_MEM_H__ */
