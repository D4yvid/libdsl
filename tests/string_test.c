#include "dsl/string.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
        assert(strlen("Hello") == __dsl_strlen("Hello"));
}
