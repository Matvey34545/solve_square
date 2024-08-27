#include "working_command_line_arguments.h"
#include "unit_test.h"
#include "argc.h"
#include "my_assert.h"
#include "printf_color.h"
#include "solve_square.h"

#include <stdio.h>
#include <stdlib.h>

/*!
Считывает коэффиценты квадратного уравнения с командной строки, решает уравнение и выводит корни на экран
\param[in] coefficientes Коэффиценты квадратного уравнения
\param[in] roots корни квадратного уравнения
*/
static void solve_square_without_arg_command_lines(Coefficientes* coefficientes, Roots *roots);

/*!
Выводит информацию по работе с программой на экран
*/
static void puts_help();

static void solve_square_without_arg_command_lines(Coefficientes* coefficientes, Roots *roots)
{
    enter_coefficients(coefficientes);
    solve_square(coefficientes, roots);
    output_roots(roots);
}

static void puts_help()
{
    puts("This program solves the quadratic equation.\n"
         "To get the manual, press -h or -help.\n"
         "To check the program, click -t or -test.\n"
         "To enter data directly into the console, click -u or -user.\n");
}

SolveSquareError reads_command_line_arguments(int *line_number_with_file, DefiningFlags* defining_flags, Coefficientes *coefficientes, int argc, char **argv)
{
    EnumKey FlagType = HELP;
    int command_line_number = 1;
    SolveSquareError error_solve_square = SOLVE_SQUARE_ERROR_NO_ERROR;

    while ( command_line_number < argc )
    {
        FlagType = comparison_with_possible_arguments(argv[command_line_number], command_line_number, argc);
        switch (FlagType)
        {
            case HELP:
                defining_flags->is_help = true;
                break;
            case TEST:
                defining_flags->is_test = true;
                if ( argc - command_line_number < 2 )
                    return SOLVE_SQUARE_ERROR_FLAG;

                *line_number_with_file = command_line_number + 1;
                command_line_number += 1;
                break;
            case USER:
                defining_flags->is_user = true;
                if ( argc - command_line_number < 2 )
                    return SOLVE_SQUARE_ERROR_FLAG;

                error_solve_square = enter_coefficient_from_command_line(argv + command_line_number + 1, coefficientes);
                if ( error_solve_square != SOLVE_SQUARE_ERROR_NO_ERROR )
                {
                    fprintf(stderr, "Error in Flag\n");
                    return SOLVE_SQUARE_ERROR_FLAG;
                }
                command_line_number += 3;
                break;
            case ERROR_IN_FLAG:
                fprintf(stderr, "Error in Flag\n");
                return SOLVE_SQUARE_ERROR_FLAG;
            default:
                fprintf(stderr, "Error in defining the command line argument\n");
                return SOLVE_SQUARE_ERROR_COMMAND_LINE_RECOGNITION;
                break;
        }
        command_line_number += 1;
    }
    return error_solve_square;
}

SolveSquareError performs_depending_flags(int line_number_with_file, DefiningFlags* defining_flags, Coefficientes *coefficientes, Roots *roots, int argc, char **argv)
{
    SolveSquareError error_solve_square = SOLVE_SQUARE_ERROR_NO_ERROR;
    if (error_solve_square != SOLVE_SQUARE_ERROR_NO_ERROR)
        return error_solve_square;

    if (defining_flags->is_help)
        puts_help();

    if (defining_flags->is_test)
    {
        error_solve_square = unit_test_solve_square(*(argv + line_number_with_file));
        if ( error_solve_square != SOLVE_SQUARE_ERROR_NO_ERROR )
            return error_solve_square;
    }
    if (defining_flags->is_user)
    {
        solve_square(coefficientes, roots);
        output_roots(roots);
    }
    if ( argc == 1 )
        solve_square_without_arg_command_lines(coefficientes, roots);

    return error_solve_square;
}
