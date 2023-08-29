#include "verror.h"
#include "io.h"
#include "solve_quadratic_eq.h"
#include "test.h"

#include <stdio.h>
#include <string.h>
#include <math.h>


int main (int argc, const char *argv[])
{
    if (whether_to_run_tests(argc, argv) == TESTS_NO_LAUNCH)
    {
        printf ("enter the coefficients separated by spaces:\n");

        double a = 0;
        double b = 0;
        double c = 0;
        int number_of_arg = get_coefficients (&a, &b, &c); /// gets the number of coefficients that are successuffully read
        int desired_narg = 3;

        if (number_of_arg == desired_narg)
        {
            double answer1 = 0;
            double answer2 = 0;
            enum NUMBER_OF_SOLUTIONS number_of_roots = solve_quadratic_equation (a, b, c, &answer1, &answer2);
            
            print_roots (number_of_roots, answer1, answer2);
        }
        else
        {
            VERROR ("unexpected EOF in string");
        }
    }

    return 0;
}
