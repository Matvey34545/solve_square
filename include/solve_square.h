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
* ������ ����������� ����������� ��������� � ������ ����������
* @param [in] coefficientes  ����������� ����������� ���������
*/
void enter_coefficients(Coefficientes *coefficientes);

/*!
������ ����������� ����������� ��������� � ������ ���������� ����� ��������� ������
\param[in] coefficientes  ����������� ����������� ���������
\return ������ �����
*/
SolveSquareError enter_coefficient_from_command_line(char** argv, Coefficientes *coefficient);
/*!
������� ����� ����������� ��������� � ����� ������������ ������
\param[out] roots ����� ����������� ���������
*/
void output_roots(const Roots *roots);

/*!
������ ���������� ���������
\param[out] a ����������� ����������� ���������
\param[in] x1 ����� ����������� ���������
*/
void solve_square(const Coefficientes *coefficientes, Roots *roots);

#endif






