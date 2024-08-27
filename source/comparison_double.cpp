#include "comparison_double.h"
#include "my_assert.h"

#include <stdlib.h>

int comprasion_with_zero(double epsilon, double a)
{
    if ( a >= epsilon )
        return 1;

    if ( a >= -epsilon )
        return 0;

    return -1;
}

