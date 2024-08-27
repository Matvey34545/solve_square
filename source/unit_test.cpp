#include "unit_test.h"
#include "comparison_double.h"
#include "my_assert.h"

#include <stdio.h>
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
static bool test_solve_square(const CoefficientesAndRoots *expected_answer_for_test, Roots* roots);

/*!
Сравнивает корни квадратного уравнения
\param[out] roots_1 Корни первого уравнения
\param[out] roots_2 Корни второго уравнения
\return Если корни равны - 0, не равны - 1, при ошибке входных параметров обрывает программу
*/
static int comprasion_roots(const Roots *roots_1, const Roots *roots_2);

SolveSquareError unit_test_solve_square(const char* filename)
{
    bool result_test = true;
    FILE *fp = fopen(filename, "r");
    if ( fp == NULL )
        return SOLVE_SQUARE_ERROR_NO_FILE_WHITH_UNIT_TESTS;

    CoefficientesAndRoots expected_answer_for_test = {};
    Roots roots = {};

    for ( int number_test = 0; fscanf(fp, "%lf", &(expected_answer_for_test.coefficientes.a)) != EOF; ++number_test )
    {
        fscanf(fp, "%lf", &(expected_answer_for_test.coefficientes.b));
        fscanf(fp, "%lf", &(expected_answer_for_test.coefficientes.c));
        fscanf(fp, "%d", (int*)&(expected_answer_for_test.roots.number_of_roots));
        fscanf(fp, "%lf", &(expected_answer_for_test.roots.x1));
        fscanf(fp, "%lf", &(expected_answer_for_test.roots.x2));
        result_test = test_solve_square(&expected_answer_for_test, &roots);
        if (result_test)
            printf("#TEST %d PASSED\n", number_test + 1);

        else
        {
            printf("Error in %d test.\nExpected: ", number_test + 1);
            output_roots(&expected_answer_for_test.roots);
            puts("Real: ");
            output_roots(&roots);

        }
    }
    fclose(fp);
    return SOLVE_SQUARE_ERROR_NO_ERROR;
}

static bool test_solve_square(const CoefficientesAndRoots *expected_answer_for_test, Roots* roots)
{
    assert(expected_answer_for_test != NULL, "NULLPTR");

    solve_square(&expected_answer_for_test->coefficientes, roots);
    if ( !comprasion_roots(roots, &expected_answer_for_test->roots) )
        return false;

    return true;
}

static int comprasion_roots(const Roots *roots_1, const Roots *roots_2)
{
    assert(roots_1 != NULL, "NULLPTR")
    assert(roots_2 != NULL, "NULLPTR");

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
            assert(false, "Error in comparison. Unreachable");
            return -1;
            break;
    }
}







