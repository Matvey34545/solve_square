#ifndef MY_ASSERT
#define MY_ASSERT
#include "printf_color.h"
#include <stdio.h>

#define assert(x, STR) if ((x) == 0)\
    {                          \
        fprintf_red(stderr, "%s\nIn line: %d\n"\
        "In file: %s\nIn function: %s\n",\
        STR, __LINE__, __FILE__, __FUNCTION__);\
        abort();\
    }

#define soft_assert(x, STR, ...) if ((x) == 0)\
    {                          \
        fprintf(stderr, "%s\nIn line: %d\n"\
        "In file: %s\nIn function: %s\n",\
        STR, __LINE__, __FILE__, __FUNCTION__);\
        __VA_LIST__;\
    }

#endif
