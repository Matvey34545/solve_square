#include "solve_square.h"
#include "unit_test.h"
#include "argc.h"
#include "my_assert.h"

#include <stdio.h>
#include <stdlib.h>

void solve_square_without_arg_command_lines(Coefficientes* coefficientes, Roots *roots);
void puts_heip();
void solve_square_user(Coefficientes* coefficientes, Roots *roots, char **argv);

int main(int argc, char *argv[])
{
    Coefficientes coefficientes = {0.0, 0.0, 0.0};
    Roots roots = {NO_ROOTS, 0.0, 0.0};
    EnumKey key_number = HELP;
    int command_line_number = 1;
    while ( command_line_number < argc )
    {
        key_number = comparison_with_possible_arguments(argv[command_line_number]);
        switch (key_number)
        {
            case HELP:
                puts_heip();
                break;
            case TEST:
                unit_test_solve_square();
                break;
            case USER:
                assert(argc - command_line_number > 3, "Error in Flag\n");
                solve_square_user(&coefficientes, &roots, argv + command_line_number + 1);
                command_line_number += 3;
                break;
            case WITHOUT_ARG:
                solve_square_without_arg_command_lines(&coefficientes, &roots);
                break;
            default:
                fprintf(stderr, "Error in defining the command line argument\n");
                break;
        }
        command_line_number++;
    }
    if ( argc == 1 )
        solve_square_without_arg_command_lines(&coefficientes, &roots);

}

void solve_square_without_arg_command_lines(Coefficientes* coefficientes, Roots *roots)
{
    enter_coefficients(coefficientes);
    solve_square(coefficientes, roots);
    output_roots(roots);
}

void puts_heip()
{
    puts("This program solves the quadratic equation.\n"
         "To get the manual, press -h or -help.\n"
         "To check the program, click -t or -test.\n"
         "To enter data directly into the console, click -u or -user.\n");
}

void solve_square_user(Coefficientes* coefficientes, Roots *roots, char **argv)
{
    enter_coefficient_from_command_line(argv, coefficientes);
    solve_square(coefficientes, roots);
    output_roots(roots);
}
