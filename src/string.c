#include "dsl/number.h"
#include "dsl/types.h"
#include "dsl/string.h"

u32 strlen(const i8 *string)
{
	u32 size = 0;

	if (!string) return 0;

	while (string[size++]);

	return size - 1;
}

void strupper(const i8 *source, i8 *out)
{
	i32 i;

	for (i = 0; i < strlen(source); i++)
	{
		if (ischr(source[i]))
		{
			out[i] = source[i] & ~(STRING_CASE_MASK);
		}
	}
}

void strlower(const i8 *source, i8 *out)
{
	i32 i;

	for (i = 0; i < strlen(source); i++)
	{
		if (!ischr(source[i]))
			continue;

		out[i] = source[i] | STRING_CASE_MASK;
	}
}

i32 strtoi32(const i8 *string)
{
	i32 num = 0;
	bool negative = false;

	u32 len = strlen(string);

	if (len == 0)
		return 0;

	if (string[0] == '-')
	{
		negative = true;

		string++;
		len--;
	}

	int i;

	for (i = 0; i < len; i++)
	{
		if (!isnum(string[i]))
			break;

		num = num * 10 + (string[i] - '0');
	}

	if (negative)
		num *= -1;

	return num;
}

i8 *i32tostr(i32 num, i8 *buf, u32 size)
{
	i32 digit_count = get_digit_count(num);
	i32 i;

	digit_count = min(digit_count, size);

	for (i = digit_count; i > 0; i--)
	{
		buf[i - 1] = (num % 10) + '0';
	}

	buf[digit_count] = 0;

	return buf;
}

bool isnum(const i8 val)
{
	return (val >= '0' && val <= '9');
}

bool ischr(const i8 val)
{
	return (val >= 'a' && val <= 'z') ||
	       (val >= 'A' && val <= 'Z');
}

bool strequal(const i8 *rhs, const i8 *lhs)
{
	i32 i;

	u32 len_rhs = strlen(rhs);
	u32 len_lhs = strlen(lhs);

	if (len_lhs != len_rhs)
		return false;

	for (i = 0; i < len_rhs; i++)
		if (rhs[i] != lhs[i])
			return false;

	return true;
}
