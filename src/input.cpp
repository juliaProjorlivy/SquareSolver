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


#include "input.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

/*!
	\brief Clears the input buffer
    \param is_eof indicate the EOF    
*/
void clear_buf(int *is_eof)
{
    int symbol = 0;
    while ((symbol = getchar())!= '\n' && symbol!= EOF)
        ;
    if(symbol == EOF){
       *is_eof = 1;
    }
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
    assert(a!=NULL);
    assert(b!=NULL);
    assert(c!=NULL);

    int nCoef = 3;
    int check = scanf("%lf%lf%lf", a, b, c);
    int is_eof = 0;
    while (check != nCoef && check!=EOF)
    {
        clear_buf(&is_eof);
        printf("incorrect input! please, try again.\n");
        check = scanf("%lf%lf%lf", a, b, c);
    }

    return check;
}

