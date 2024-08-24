#include "argc.h"

#include <string.h>
#include <stdlib.h>

EnumKey comparison_with_possible_arguments(const char *argv)
{
    Key key_for_argv[] =
    {
        {{"-h"},  {"-help"}}, //return 0
        {{"-t"},  {"-test"}}, //return 1
        {{"-u"},  {"-user"}}  //return 2
    };

    size_t quantity_key = sizeof(key_for_argv) / sizeof(Key);
    bool result = true;
    size_t i = 0;
    while ( i < quantity_key && result )
    {
        if ( strcmp(argv, key_for_argv[i].short_key) == 0 || strcmp(argv, key_for_argv[i].long_key) == 0 )
            result = false;

        i++;
    }
    if (result)
        return (EnumKey)i;

    return (EnumKey)(i - 1);
}
