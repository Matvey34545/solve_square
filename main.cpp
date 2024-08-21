#include "solve_square.h"
#include "comparison_double.h"

int main()
{
    Coefficientes coefficientes = {0.0, 0.0, 0.0};
    Roots roots = {NO_ROOTS, 0.0, 0.0};
    enter_coefficients(&coefficientes);
    solve_square(&coefficientes, &roots);
    output_roots(&roots);
}
