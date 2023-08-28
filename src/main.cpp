/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The main file of the project
 *
 *        Created:  24/08/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#include "verror.h"
#include "input.h"
#include "solve_quadratic_eq.h"

/**
 * include test.h in case of running the tests
 */
// #ifdef RUN_TESTS
#include "test.h"
// #endif

#include <stdio.h>
#include <string.h>
#include <math.h>

void state_roots(int number_of_roots, double answer1, double answer2);

int main(int argc, char *argv[])
{
    /**
     * run tests
     */
    if (argc >= 2)
    {
        if (!strcmp(argv[1], "--UnitTest"))
        {
            if (argc == 2)
            {
                run_default_tests();
            }
            else
            {
                const char *file_name = argv[2];
                if (run_tests(file_name))
                {
                    return FTEST_FAILURE;
                }
            }
            return 0;
        }
    }

    (void)argc;
    (void)argv;

#ifndef RUN_TESTS
    printf("enter the coefficients separated by spaces:\n");

    double a = 0, b = 0, c = 0;
    int number_of_arg = get_coefficients(&a, &b, &c); /// gets the number of coefficients that are successuffully read
    int desired_narg = 3;

    if (number_of_arg == desired_narg)
    {
        printf("%lf %lf %lf\n", a, b, c);

        double answer1 = 0, answer2 = 0;
        int number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);
        state_roots(number_of_roots, answer1, answer2);
    }
    else
    {
        VERROR("unexpected EOF in string");
    }
#endif
    return 0;
}

void state_roots(int number_of_roots, double answer1, double answer2)
{
    switch (number_of_roots) /*various numbers of solutions to a quadtratic equation*/
    {
    case NO_ROOTS:
        printf("no roots\n");
        break;
    case ONE_ROOT:
        printf("the root is:\nx = %lf\n", answer1);
        break;
    case TWO_ROOTS:
        printf("the roots are:\nx1 = %lf\nx2 = %lf\n", answer1, answer2);
        break;
    case INFINITY_SOL:
        printf("infinite number of roots\n");
        break;
    default:
        VERROR("unexpected number of solutions:%d", number_of_roots);
    }
}
