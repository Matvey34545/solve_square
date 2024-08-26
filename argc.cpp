#include "argc.h"
#include "my_assert.h"

#include <string.h>
#include <stdlib.h>

EnumKey comparison_with_possible_arguments(char *argv, int command_line_number, int argc)
{
    Flag help  = {{"-h"},  {"--help"}};
    Flag test  = {{"-t"},  {"--test"}};
    Flag user =  {{"-u"},  {"--user"}};

    if ( strcmp(argv, help.short_flag) == 0 || strcmp(argv, help.long_flag) == 0 )
        return HELP;

    if ( strcmp(argv, test.short_flag) == 0 || strcmp(argv, test.long_flag) == 0 )
    {
        if ( argc - command_line_number < 2 )
            return ERROR_IN_FLAG;

        return TEST;
    }
    if ( strcmp(argv, user.short_flag) == 0 || strcmp(argv, user.long_flag) == 0 )
    {
        if ( argc - command_line_number < 4 )
            return ERROR_IN_FLAG;

        return USER;
    }
    return ERROR_IN_FLAG;
}
