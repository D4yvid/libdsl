#include "dsl/math.h"
#include "dsl/types.h"

u32 align_num(u32 num, u32 alignment)
{
	return (num + alignment - 1) & ~(alignment - 1);
}
