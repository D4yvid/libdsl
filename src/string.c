#include "dsl/string.h"
#include "dsl/types.h"

u32 __dsl_strlen(const i8 *string)
{
        if (string == NULL) {
                return 0;
        }

        u32 size = 0;

        while (string[size++]);

        return size - 1;
}
