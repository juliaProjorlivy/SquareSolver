#include "io.h"
#include "solve_quadratic_eq.h"
#include "test.h"
#include "verror.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

enum TEST_STATE whether_to_run_tests (int argc, const char *argv[])
{
    assert(argv != NULL);

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
        return FTEST_SUCCESS;
    }
    return TESTS_NO_LAUNCH;
}

void clear_buf()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n' && symbol != EOF)
        ;
}

int get_coefficients (double *a, double *b, double *c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    int nCoef = 3;
    int check = scanf ("%lf %lf %lf", a, b, c);

    while (check != nCoef && check != EOF)
    {
        clear_buf ();
        printf ("incorrect input! please, try again.\n");
        check = scanf ("%lf %lf %lf", a, b, c);
    }

    return check;
}

void print_roots (enum NUMBER_OF_SOLUTIONS number_of_roots, double answer1, double answer2)
{
    switch (number_of_roots) /*various numbers of solutions to a quadtratic equation*/
    {
    case NO_ROOTS:
        printf ("no roots\n");
        break;
    case ONE_ROOT:
        printf ("the root is:\nx = %lf\n", answer1);
        break;
    case TWO_ROOTS:
        printf ("the roots are:\nx1 = %lf\nx2 = %lf\n", answer1, answer2);
        break;
    case INFINITY_SOL:
        printf ("infinite number of roots\n");
        break;
    default:
        VERROR ("unexpected number of solutions:%d", number_of_roots); 
    }
}
