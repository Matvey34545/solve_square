#include "unit_test.h"
#include "comparison_double.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct CoefficientesAndRoots
{
    Coefficientes coefficientes;
    Roots roots;
};

/*!
Проверяет функцию solve_square а одном тесте
\param[out] number_test Номер теста
\param[out] expected_answer_for_test Коэффиценты и ожидаемые ответы для этих коэффицентов
\return Если тест пройден true, если нет - false
*/
static bool test_solve_square(int number_test, const CoefficientesAndRoots *expected_answer_for_test);

/*!
Сравнивает корни квадратного уравнения
\param[out] roots_1 Корни первого уравнения
\param[out] roots_2 Корни второго уравнения
\return Если корни равны - 0, не равны - 1, при ошибке входных параметров -1
*/
static int comprasion_roots(const Roots *roots_1, const Roots *roots_2);

void unit_test_solve_square()
{
    bool result_test = true;
    CoefficientesAndRoots expected_answer_for_test[] =
    {
        {{0.0, 0.0,  0.0}, {INFINITY_ROOTS, 0.0, 0.0}},
        {{0.0, 0.0,  1.0}, {NO_ROOTS,       0.0, 0.0}},
        {{0.0, 1.0, -3.0}, {ONE_ROOT,       3.0, 0.0}},
        {{1.0, 2.0,  1.0}, {ONE_ROOT,      -2.0, 0.0}},
        {{1.0, 2.0,  4.0}, {NO_ROOTS,       0.0, 0.0}},
        {{1.0, 5.0,  0.0}, {TWO_ROOTS,     -5.0, 0.0}}
    };

    size_t quantity_test = sizeof(expected_answer_for_test) / sizeof(CoefficientesAndRoots);
    for ( size_t i = 0; i < quantity_test && result_test; ++i )
    {
        result_test = test_solve_square(i, &expected_answer_for_test[i]);
    }
}

static bool test_solve_square(int number_test, const CoefficientesAndRoots *expected_answer_for_test)
{
    Roots roots = {NO_ROOTS, 0.0, 0.0};

    assert(expected_answer_for_test != NULL);
    assert(comprasion_roots(&roots, &expected_answer_for_test->roots) != -1);

    solve_square(&expected_answer_for_test->coefficientes, &roots);
    if ( !comprasion_roots(&roots, &expected_answer_for_test->roots) )
    {
        printf("Error in %d test.\n Expected: ", number_test);
        output_roots(&expected_answer_for_test->roots);
        puts("Real: ");
        output_roots(&roots);
        return false;
    }
    else
    {
        return true;
    }
}

static int comprasion_roots(const Roots *roots_1, const Roots *roots_2)
{
    assert(roots_1 != NULL && roots_2 != NULL);
    if ( roots_1->number_of_roots != roots_2->number_of_roots)
        return 0;

    switch (roots_1->number_of_roots)
    {
        case NO_ROOTS:
            return 1;
            break;
        case INFINITY_ROOTS:
            return 1;
            break;
        case ONE_ROOT:
            if ( !comprasion_with_zero(EPSILON, roots_1->x1 - roots_2->x1) )
                return 1;

            else
                return 0;

            break;
        case TWO_ROOTS:
            if ( !comprasion_with_zero(EPSILON, roots_1->x1 - roots_2->x1) && !comprasion_with_zero(EPSILON, roots_1->x2 - roots_2->x2)  )
                return 1;

            else
                return 0;

            break;
        default:
            return -1;
            break;
    }
}







