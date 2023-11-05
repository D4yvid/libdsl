#include "dsl/mem.h"
#include "dsl/types.h"

void memcpy(void *dest, void *src, u64 size)
{
	u64 i;
	for (i = 0; i < size; i++)
	{
		((u8 *) dest)[i] = ((u8 *) src)[i];
	}
}

bool memcmp(void *rhs, void *lhs, u64 size)
{
	u64 i;
	for (i = 0; i < size; i++)
	{
		if (((u8 *) rhs)[i] != ((u8 *) lhs)[i])
			return false;
	}

	return true;
}

void *alloc(u64 size)
{
	static int _heap_initialized = 0;

	if (!_heap_initialized)
	{
	}

	return NULL;
}

void free(void *ptr)
{

}
