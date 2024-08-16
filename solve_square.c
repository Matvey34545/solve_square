#include <stdio.h>
#include <math.h>
#define epsilon 0.0000000001

enum number_roots
{
    no_roots,
    one_root,
    two_roots,
    infinity_roots
};

enum number_roots solve_square(double a, double b, double c, double* x1, double* x2);
enum number_roots solve_linal(double a, double b, double* x1, double* x2);
enum number_roots solve_standart_square(double a, double b, double c, double* x1, double* x2);
double data_verification();

int main()
{
    double a, b, c, x1, x2;
    enum number_roots roots;
    puts("Please enter the coefficient a");
    a = data_verification();
    puts("Please enter the coefficient b");
    b = data_verification();
    puts("Please enter the coefficient c");
    c = data_verification();
    roots = solve_square(a, b, c, &x1, &x2);
    switch (roots)
    {
        case no_roots:
            puts("This equation has no roots");
            break;
        case infinity_roots:
            puts("Any number is the root of this equation");
            break;
        case one_root:
            printf("This equation has one root: %lf", x1);
            break;
        case two_roots:
            printf("This equation has two root\nThe first root: %lf\nThe second root: %lf", x1, x2);
            break;
    }
}

enum number_roots solve_square(double a, double b, double c, double* x1, double* x2)
{
    enum number_roots roots;
    if ( a == 0.0 )
    {
        roots = solve_linal(b, c, x1, x2);
    }
    else
    {
        roots = solve_standart_square(a, b, c, x1, x2);
    }
    return roots;
}

enum number_roots solve_linal(double a, double b, double* x1, double* x2)
{
    if ( a == 0.0 )
    {
        if ( b == 0.0 )
        {
            return infinity_roots;
        }
        else
        {
            return no_roots;
        }
    }
    else
    {
        *x1 = -b/a;
        return one_root;
    }
}

enum number_roots solve_standart_square(double a, double b, double c, double* x1, double* x2)
{
    double D = 1 - 4*a*c/b/b;
    if ( D <= -epsilon )
    {
        return no_roots;
    }
    else
    {
        if ( D <= epsilon )
        {
            *x1 = -b/2/a;
            return one_root;
        }
        else
        {
            *x1 = b*(-1.0 - sqrt(D))/2/a;
            *x2 = b*(-1.0 + sqrt(D))/2/a;
            return two_roots;
        }
    }
}

double data_verification()
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




