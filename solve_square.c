#include <stdio.h>
#include <math.h>
#include <assert.h>

const double EPSILON = 0.0000000001;

enum NumberOfRoots
{
    NO_ROOTS       = 0,
    ONE_ROOT       = 1,
    TWO_ROOTS      = 2,
    INFINITY_ROOTS = 3
};

NumberOfRoots solve_square(double a, double b, double c, double *x1, double *x2);
NumberOfRoots solve_linal(double a, double b, double *x1);
NumberOfRoots solve_standart_square(double a, double b, double c, double *x1, double *x2);
double receive_coefficient();
void enter_coefficients(double *a, double *b, double *c);
void output_roots(double x1, double x2, NumberOfRoots number_of_r4oots);
int comprasion_with_zero(double epsilon, double a);
int promotes_input(char *s);

int main()
{
    double a  = 0;
    double b  = 0;
    double c  = 0;
    double x1 = 0;
    double x2 = 0;
    enum NumberOfRoots number_of_roots;
    enter_coefficients(&a, &b, &c);
    number_of_roots = solve_square(a, b, c, &x1, &x2);
    output_roots(x1, x2, number_of_roots);
}

NumberOfRoots solve_square(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    enum NumberOfRoots number_of_roots;
    if ( comprasion_with_zero(EPSILON, a) == 0 )
    {
        number_of_roots = solve_linal(b, c, x1);
    }
    else
    {
        number_of_roots = solve_standart_square(a, b, c, x1, x2);
    }
    return number_of_roots;
}

NumberOfRoots solve_linal(double a, double b, double *x1)
{
    if ( comprasion_with_zero(EPSILON, a) == 0 )
    {
        if ( comprasion_with_zero(EPSILON, a) == 0 )
        {
            return INFINITY_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        *x1 = -b/a;
        return ONE_ROOT;
    }
}

NumberOfRoots solve_standart_square(double a, double b, double c, double *x1, double *x2)
{
    double D = 1 - 4*a*c/b/b;
    if ( comprasion_with_zero(EPSILON, D) == -1 )
    {
        return NO_ROOTS;
    }
    else
    {
        if ( comprasion_with_zero(EPSILON, D) == 0 )
        {
            *x1 = -b/2/a;
            return ONE_ROOT;
        }
        else
        {
            double sqrt_D = sqrt(D);
            *x1 = b*(-1.0 - sqrt_D)/2/a;
            *x2 = b*(-1.0 + sqrt_D)/2/a;
            return TWO_ROOTS;
        }
    }
}

double receive_coefficient()
{
    int result_scanf;
    int number_unread_symbols;
    double scan;
    while ( number_unread_symbols > 0 )
    {
        number_unread_symbols = 0;
        result_scanf = scanf("%lf", &scan);
        if ( result_scanf == 0 )
        {
            number_unread_symbols++;
            number_unread_symbols += promotes_input("\n");
        }
        else
        {
            number_unread_symbols += promotes_input("\n");
        }
        if ( number_unread_symbols > 0 )
            puts("Error. You must enter a number");
    }
    return scan;
}

void enter_coefficients(double *a, double *b, double *c)
{
    puts("Please enter the coefficient a");
    *a = receive_coefficient();
    puts("Please enter the coefficient b");
    *b = receive_coefficient();
    puts("Please enter the coefficient c");
    *c = receive_coefficient();
}

void output_roots(double x1, double x2, NumberOfRoots number_of_roots)
{
    switch (number_of_roots)
    {
        case NO_ROOTS:
            puts("This equation has no roots");
            break;
        case INFINITY_ROOTS:
            puts("Any number is the root of this equation");
            break;
        case ONE_ROOT:
            printf("This equation has one root: %lf", x1);
            break;
        case TWO_ROOTS:
            printf("This equation has two root\nThe first root: %lf\nThe second root: %lf", x1, x2);
            break;
        default:
            puts("Error");
            break;
    }
}

int comprasion_with_zero(double epsilon, double a)
{
    if ( a >= epsilon )
        return 1;

    if ( a >= -epsilon )
        return 0;

    return -1;
}

// doxygen!
int promotes_input(char *s)
{
    int symbol = 0;
    bool is_symbol_not_found = true;
    int i = 0;
    int number_read_symbols = 0;
    while ( is_symbol_not_found )
    {
        i = 0;
        symbol = getchar();
        while ( s[i] != '\0' )
        {
            if ( symbol == s[i] )
            {
                is_symbol_not_found = false;
                break;
            }
            i++;
        }
        if ( is_symbol_not_found )
            number_read_symbols++;

    }
    return number_read_symbols;
}





