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
#include "io.h"
#include "solve_quadratic_eq.h"

/**
 * include test.h in case of running the tests
 */
#include "test.h"


#include <stdio.h>
#include <string.h>
#include <math.h>


int main (int argc, char *argv[])
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
                if (run_file_tests (file_name))
                {
                    return FTEST_FAILURE;
                }
            }
        }
        return 0;
    }

    printf ("enter the coefficients separated by spaces:\n");

    double a = 0;
    double b = 0;
    double c = 0;
    int number_of_arg = get_coefficients (&a, &b, &c); /// gets the number of coefficients that are successuffully read
    int desired_narg = 3;

    if (number_of_arg == desired_narg)
    {
        printf ("%lf %lf %lf\n", a, b, c);
    
        double answer1 = 0;
        double answer2 = 0;
        int number_of_roots = solve_quadratic_equation (a, b, c, &answer1, &answer2);
        
        print_roots (number_of_roots, answer1, answer2);
    }
    else
    {
        VERROR ("unexpected EOF in string");
    }

    return 0;
}
