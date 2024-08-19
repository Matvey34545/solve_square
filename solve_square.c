#include <stdio.h>
#include <math.h>
#define epsilon 0.0000000001

enum NUMBER_ROOTS
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFINITY_ROOTS
};

enum NUMBER_ROOTS solve_square(double a, double b, double c, double *x1, double *x2);
enum NUMBER_ROOTS solve_linal(double a, double b, double *x1, double *x2);
enum NUMBER_ROOTS solve_standart_square(double a, double b, double c, double *x1, double *x2);
double receive_data();

int main()
{
    double a, b, c, x1, x2;
    enum NUMBER_ROOTS ROOTS;
    puts("Please enter the coefficient a");
    a = receive_data();
    puts("Please enter the coefficient b");
    b = receive_data();
    puts("Please enter the coefficient c");
    c = receive_data();
    ROOTS = solve_square(a, b, c, &x1, &x2);
    switch (ROOTS)
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
    }
}

enum NUMBER_ROOTS solve_square(double a, double b, double c, double *x1, double *x2)
{
    enum NUMBER_ROOTS ROOTS;
    if ( a == 0.0 )
    {
        ROOTS = solve_linal(b, c, x1, x2);
    }
    else
    {
        ROOTS = solve_standart_square(a, b, c, x1, x2);
    }
    return ROOTS;
}

enum NUMBER_ROOTS solve_linal(double a, double b, double *x1, double *x2)
{
    if ( a == 0.0 )
    {
        if ( b == 0.0 )
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

enum NUMBER_ROOTS solve_standart_square(double a, double b, double c, double *x1, double *x2)
{
    double D = 1 - 4*a*c/b/b;
    if ( D <= -epsilon )
    {
        return NO_ROOTS;
    }
    else
    {
        if ( D <= epsilon )
        {
            *x1 = -b/2/a;
            return ONE_ROOT;
        }
        else
        {
            *x1 = b*(-1.0 - sqrt(D))/2/a;
            *x2 = b*(-1.0 + sqrt(D))/2/a;
            return TWO_ROOTS;
        }
    }
}

double receive_data()
{
    int b;
    double scan;
    b = scanf("%lf", &scan);
    while ( b == 0 )
    {
        puts("Try again. You must enter a floating point number\n");
        getchar();
        b = scanf("%lf", &scan);
    }
    return scan;
}




