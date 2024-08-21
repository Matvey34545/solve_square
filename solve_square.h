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
Вводит коэффиценты квадратного уравнения в память компьютера
\param[in] coefficientes  Коэффиценты квадратного уравнения
*/
void enter_coefficients(Coefficientes *coefficientes);

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






