/*
 * ============================================================================
 *
 *       Filename:  input.cpp
 *
 *    Description:  Reads input
 *
 *        Created:  24/08/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#include "solve_quadratic_eq.h"
#include "verror.h"
#include <assert.h>
#include <io.h>
#include <math.h>
#include <stdio.h>

/*!
    \brief Clears the input buffer
    \param is_eof indicate the EOF
*/
void clear_buf()
{
    int symbol = 0;
    while ((symbol = getchar()) != '\n' && symbol != EOF)
        ;
}

/*!
    \brief Reads input data and in case of an incorrect input asks user to type again
    \param[inout] a quadratic coefficient before x^2
    \param[inout] b quadratic coefficient before x
    \param[inout] c free term of quadratic equation
    \return the number of parametrs that were read

*/
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

void print_roots (int number_of_roots, double answer1, double answer2)
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
