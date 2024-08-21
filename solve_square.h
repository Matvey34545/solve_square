#ifndef SOLVE_SQUARE
#define SOLVE_SQUARE

const double EPSILON = 0.000000001;

enum NumberOfRoots
{
    NO_ROOTS       = 0,
    ONE_ROOT       = 1,
    TWO_ROOTS      = 2,
    INFINITY_ROOTS = 3
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

/*!
������ ����������� ����������� ��������� � ������ ����������
\param[in] coefficientes  ����������� ����������� ���������
*/
void enter_coefficients(Coefficientes *coefficientes);

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






