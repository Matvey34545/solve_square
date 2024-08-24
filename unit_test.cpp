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
    char* filename = "unit_test.txt";
    FILE *fp;
    fp = fopen(filename, "r");

    int c;
    int j = 0;
    int temp = 0;
    while ( fscanf(fp, "%lf", &temp) != EOF )
    {
        j++;
    }

    const int quantity_test = j / 6;
    CoefficientesAndRoots expected_answer_for_test[quantity_test];

    fp = fopen(filename, "r");
    for (int i = 0 ; fscanf(fp, "%lf", &(expected_answer_for_test[i].coefficientes.a)) != EOF; ++i)
    {
        fscanf(fp, "%lf", &(expected_answer_for_test[i].coefficientes.b));
        fscanf(fp, "%lf", &(expected_answer_for_test[i].coefficientes.c));
        fscanf(fp, "%d", &(expected_answer_for_test[i].roots.number_of_roots));
        fscanf(fp, "%lf", &(expected_answer_for_test[i].roots.x1));
        fscanf(fp, "%lf", &(expected_answer_for_test[i].roots.x2));
    }
    fclose(fp);
    printf("%d\n", quantity_test);
    for ( int i = 0; i < quantity_test; ++i )
    {
        result_test = test_solve_square(i + 1, &expected_answer_for_test[i]);
        if (result_test)
            printf("#TEST %d/%d PASSED\n", i + 1, quantity_test);

    }
}

static bool test_solve_square(int number_test, const CoefficientesAndRoots *expected_answer_for_test)
{
    Roots roots = {NO_ROOTS, 0.0, 0.0};

    assert(expected_answer_for_test != NULL, "NULLPTR");
    assert(comprasion_roots(&roots, &expected_answer_for_test->roots) != -1, "Error comparison");

    solve_square(&expected_answer_for_test->coefficientes, &roots);
    if ( !comprasion_roots(&roots, &expected_answer_for_test->roots) )
    {
        printf("Error in %d test.\nExpected: ", number_test);
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
            return -1;
            break;
    }
}







