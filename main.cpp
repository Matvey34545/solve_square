#include "working_command_line_arguments.h"

/**
 * @param [in]  argc - Ù˚‚Ù‚˚
 */
int main(int argc, char *argv[])
{
    SolveSquareError error_solve_square = SOLVE_SQUARE_ERROR_NO_ERROR;
    Coefficientes coefficientes = {};
    Roots roots = {};
    int line_number_with_file = 1;
    DefiningFlags defining_flags = {false, false, false};

    error_solve_square = reads_command_line_arguments(&line_number_with_file, &defining_flags, &coefficientes, argc, argv);
    if ( error_solve_square != SOLVE_SQUARE_ERROR_NO_ERROR )
        return error_solve_square;

    error_solve_square = performs_depending_flags(line_number_with_file, &defining_flags, &coefficientes, &roots, argc, argv);
    return error_solve_square;
}





