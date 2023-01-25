#include <stdio.h>
#include <assert.h>
#include "dsl/math.h"

int main(int argc, char **argv)
{
        assert(__dsl_align_num(0xfa, 0x10) == 0x100);
}
