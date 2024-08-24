#include "solve_square.h"
#include "comparison_double.h"
#include "my_assert.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*!
Решает линейное уравнение
\param[out] Коэффиценты линейного уравнения
\param[in] roots Корни линейного уравнения
*/
static void solve_linal(const Coefficientes *coefficientes, Roots *roots);

/*!
Решает квадратное уравнение с ненулевым старшим коэффицентом
\param[out] coefficientes Коэффиценты квадратного уравнения
\param[in] roots Корни уравнения
*/
static void solve_standart_square(const Coefficientes *coefficientes, Roots *roots);

/*!
Вводит число с клавиатуры в память компьютера
\return Число, введенное пользователем с клавиатуры
*/
static double receive_coefficient();

/*!
Вводит число с командной строки в память компьютера
\return Число, введенное пользователем с клавиатуры
*/
static void receive_coefficient_from_command_line(char *argv, double *coefficient);

/*!
Считывает символы из стандартного потока ввода до тех пор,
пока не встретит символ, находящийся в передаваемой строке.
\param[in] s Указатель на передаваемую строку
\return Количество считанных символов, за исключением непечатаеммых минус 1
*/
static int promotes_input(char *s);

void solve_square(const Coefficientes *coefficientes, Roots *roots)
{
    assert(coefficientes != NULL, "NULLPTR");
    assert(roots != NULL, "NULLPTR");

    if ( comprasion_with_zero(EPSILON, coefficientes->a) == 0 )
    {
        solve_linal(coefficientes, roots);
    }
    else
    {
        solve_standart_square(coefficientes, roots);
    }
}

static void solve_linal(const Coefficientes *coefficientes, Roots *roots)
{
    assert(coefficientes != NULL, "NULLPTR");
    assert(roots != NULL, "NULLPTR");
    assert(comprasion_with_zero(EPSILON, coefficientes->a) == 0, "Error comparison");

    if ( comprasion_with_zero(EPSILON, coefficientes->b) == 0 )
    {
        if ( comprasion_with_zero(EPSILON, coefficientes->c) == 0 )
        {
            roots->number_of_roots = INFINITY_ROOTS;
        }
        else
        {
            roots->number_of_roots = NO_ROOTS;
        }
    }
    else
    {
        roots->x1 = -coefficientes->c / coefficientes->b;
        roots->number_of_roots = ONE_ROOT;
    }
}

static void solve_standart_square(const Coefficientes *coefficientes, Roots *roots)
{
    assert(coefficientes != NULL, "NULLPTR");
    assert(roots != NULL, "NULLPTR");

    double D = 1 - 4 * coefficientes->a * coefficientes->c / (coefficientes->b * coefficientes->b);
    if ( comprasion_with_zero(EPSILON, D) == -1 )
    {
        roots->number_of_roots = NO_ROOTS;
    }
    else
    {
        if ( comprasion_with_zero(EPSILON, D) == 0 )
        {
            roots->x1 = -coefficientes->b / (2 * coefficientes->a);
            roots->number_of_roots = ONE_ROOT;
        }
        else
        {
            double sqrt_D = sqrt(D);
            roots->x1 = coefficientes->b * (-1.0 - sqrt_D) / (2 * coefficientes->a);
            roots->x2 = coefficientes->b*(-1.0 + sqrt_D) / (2 * coefficientes->a);
            roots->number_of_roots = TWO_ROOTS;
        }
    }
}

static double receive_coefficient()
{
    int result_scanf = 0;
    int number_unread_symbols = 1;
    double scan = 0.0;
    char s[] = "\n";
    while ( number_unread_symbols > 0 )
    {
        number_unread_symbols = 0;
        result_scanf = scanf("%lf", &scan);
        if ( result_scanf == 0 )
        {
            number_unread_symbols++;
            number_unread_symbols += promotes_input(s);
        }
        else
        {
            number_unread_symbols += promotes_input(s);
        }
        if ( number_unread_symbols > 0 )
            puts("Error. You must enter a number\n");
    }
    return scan;
}

static void receive_coefficient_from_command_line(char* argv, double *coefficient)
{
    int result_sscanf = 0;
    result_sscanf = sscanf(argv, "%lf", coefficient);
    assert(result_sscanf != 0, "Error in Flag\n");
}

void enter_coefficient_from_command_line(char **argv, Coefficientes *coefficient)
{
    receive_coefficient_from_command_line(*argv, &coefficient->a);
    receive_coefficient_from_command_line(*(argv + 1), &coefficient->b);
    receive_coefficient_from_command_line(*(argv + 2), &coefficient->c);
}

void enter_coefficients(Coefficientes *coefficientes)
{
    assert(coefficientes != NULL, "NULLPTR");

    puts("Please enter the coefficient a");
    coefficientes->a = receive_coefficient();
    puts("Please enter the coefficient b");
    coefficientes->b = receive_coefficient();
    puts("Please enter the coefficient c");
    coefficientes->c = receive_coefficient();
}

void output_roots(const Roots *roots)
{
    assert(roots != NULL, "NULLPTR");

    switch (roots->number_of_roots)
    {
        case NO_ROOTS:
            puts("This equation has no roots\n");
            break;
        case INFINITY_ROOTS:
            puts("Any number is the root of this equation\n");
            break;
        case ONE_ROOT:
            printf("This equation has one root: %lf\n", roots->x1);
            break;
        case TWO_ROOTS:
            printf("This equation has two root\nThe first root: %lf\nThe second root: %lf\n", roots->x1, roots->x2);
            break;
        default:
            fprintf(stderr, "Error output\n");
            break;
    }
}

static int promotes_input(char *s)
{
    assert(s != NULL, "NULLPTR");

    int symbol = 0;
    bool is_symbol_not_found = true;
    int i = 0;
    int number_read_symbols = 0;
    while ( is_symbol_not_found )
    {
        i = 0;
        symbol = getchar();
        if ( symbol != ' ' && symbol != '\t' ) // KOLYA: знает про isspace(), тут не подходит
        {
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
    }
    return number_read_symbols;
}






