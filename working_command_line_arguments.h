#ifndef WORKING_COMMAND_LINE_ARGUMENTS
#define WORKING_COMMAND_LINE_ARGUMENTS
#include "solve_square.h"

SolveSquareError reads_command_line_arguments(int *line_number_with_file, DefiningFlags* defining_flags, Coefficientes *coefficientes, int argc, char **argv);
SolveSquareError performs_depending_flags(int line_number_with_file, DefiningFlags* defining_flags, Coefficientes *coefficientes, Roots *roots, int argc, char **argv);
#endif
