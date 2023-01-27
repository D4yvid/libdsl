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

void __dsl_strupper(const i8 *source, i8 *out)
{
        i32 i;
        for (i = 0; i < __dsl_strlen(source); i++)
        {
                if (__dsl_ischr(source[i]))
                {
                        out[i] = source[i] & ~(STRING_CASE_MASK);
                }
        }
}

void __dsl_strlower(const i8 *source, i8 *out)
{
        i32 i;
        for (i = 0; i < __dsl_strlen(source); i++)
        {
                if (__dsl_ischr(source[i]))
                {
                        out[i] = source[i] | STRING_CASE_MASK;
                }
        }
}

i32 __dsl_strtoi32(const i8 *string)
{
        i32 num = 0;
        bool negative = false;

        u32 len = __dsl_strlen(string);

        if (len == 0)
        {
                return 0;
        }

        if (string[0] == '-')
        {
                negative = true;
                string++;
                len--;
        }

        int i;
        for (i = 0; i < len; i++)
        {
                if (!__dsl_isnum(string[i]))
                        break;

                num = num * 10 + (string[i] - '0');
        }

        if (negative)
                num *= -1;

        return num;
}

bool __dsl_isnum(const i8 val)
{
        return (val >= '0' && val <= '9');
}

bool __dsl_ischr(const i8 val)
{
        return (val >= 'a' && val <= 'z') ||
               (val >= 'A' && val <= 'Z');
}

bool __dsl_strequal(const i8 *rhs, const i8 *lhs)
{
        u32 len_rhs = __dsl_strlen(rhs);
        u32 len_lhs = __dsl_strlen(lhs);

        if (len_lhs != len_rhs)
                return false;

        i32 i;

        for (i = 0; i < len_rhs; i++)
        {
                if (rhs[i] != lhs[i])
                        return false;
        }

        return true;
}
