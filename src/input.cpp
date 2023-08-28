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

#include <input.h>
#include <assert.h>
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
int get_coefficients(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    int nCoef = 3;
    int check = scanf("%lf %lf %lf", a, b, c);

    while (check != nCoef && check != EOF)
    {
        clear_buf();
        printf("incorrect input! please, try again.\n");
        check = scanf("%lf %lf %lf", a, b, c);
    }

    return check;
}
