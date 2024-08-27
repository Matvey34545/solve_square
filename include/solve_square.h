#ifndef SOLVE_SQUARE
#define SOLVE_SQUARE

#include <stdlib.h>

const double EPSILON = 0.000000001;
const size_t MAX_SIZE_FILE = 100;

enum NumberOfRoots
{
    NO_ROOTS       = 0,
    ONE_ROOT       = 1,
    TWO_ROOTS      = 2,
    INFINITY_ROOTS = 3
};

enum SolveSquareError
{
    SOLVE_SQUARE_ERROR_FLAG                     = 1,
    SOLVE_SQUARE_ERROR_COMMAND_LINE_RECOGNITION = 2,
    SOLVE_SQUARE_ERROR_NO_FILE_WHITH_UNIT_TESTS = 3,
    SOLVE_SQUARE_ERROR_NO_ERROR                 = 4,
};

struct DefiningFlags
{
    bool is_help;
    bool is_test;
    bool is_user;
};

struct Coefficientes
{
    double a;
    double b;
    double c;
};

struct Roots
{
    NumberOfRoots number_of_roots;
    double x1;
    double x2;
};

/**
* Вводит коэффиценты квадратного уравнения в память компьютера
* @param [in] coefficientes  Коэффиценты квадратного уравнения
*/
void enter_coefficients(Coefficientes *coefficientes);

/*!
Вводит коэффиценты квадратного уравнения в память компьютера через командную строку
\param[in] coefficientes  Коэффиценты квадратного уравнения
\return ошибку ввода
*/
SolveSquareError enter_coefficient_from_command_line(char** argv, Coefficientes *coefficient);
/*!
Выводит корни квадратного уравнения в поток стандартного вывода
\param[out] roots Корни квадратного уравнения
*/
void output_roots(const Roots *roots);

/*!
Решает квадратное уравнение
\param[out] a Коэффиценты квадратного уравнения
\param[in] x1 Корни квадратного уравнения
*/
void solve_square(const Coefficientes *coefficientes, Roots *roots);

#endif






