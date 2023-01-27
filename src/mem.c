#include "dsl/mem.h"
#include "dsl/types.h"

struct __dsl_free_block *initial;

__DSL_PRIV_API__
void __dsl_init_heap();

void __dsl_memcpy(void *dest, void *src, u64 size)
{
        u64 i;
        for (i = 0; i < size; i++)
        {
                ((u8 *) dest)[i] = ((u8 *) src)[i];
        }
}

bool __dsl_memcmp(void *rhs, void *lhs, u64 size)
{
        u64 i;
        for (i = 0; i < size; i++)
        {
                if (((u8 *) rhs)[i] != ((u8 *) lhs)[i])
                        return false;
        }

        return true;
}

void *__dsl_alloc(u64 size)
{
        static int _heap_initialized = 0;

        if (!_heap_initialized)
        {
                __dsl_init_heap();
        }

        return NULL;
}

void __dsl_free(void *ptr)
{

}

void __dsl_init_heap()
{
        
}
