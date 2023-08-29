/* ============================================================================
 *
 *       Filename:  solve_quadratic_eq.h
 *
 *    Description:  Header file for quadtratid equation function
 *
 *        Created:  24/03/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#ifndef SOLVE_QUADRATIC_EQ_INCLUDED
#define SOLVE_QUADRATIC_EQ_INCLUDED

/// @brief precision number to compare numbers
const double DEF_EPSILON = 1e-9;

/// @brief the possible number of quadratic equation roots
enum NUMBER_OF_SOLUTIONS
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITY_SOL = 3
};


/*!
    \brief compare two numbers up to epsilon
    \param epsilon the precision number which by defualt equals EPSILON = 1e-9
    \return 1 if two numbers are equal and 0 if not

*/
int is_equal (double x, double y, double epsilon = DEF_EPSILON);

/*!
    \brief determines if x is less than y
    \param epsilon the precision number which by defualt equals EPSILON = 1e-9
    \return 1 if x is less than y and 0 if not
*/
int is_less (double x, double y, double epsilon = DEF_EPSILON);

/*!
    \brief solve the linear equation
    \param[in] b coefficient before x
    \param[in] c free term of linear equation
    \param[inout] answer1 linear equation root
    \return the number of linear equation roots
*/
enum NUMBER_OF_SOLUTIONS solve_linear_equation (double b, double c, double *answer1);

/*!
    \brief solve the quadratic equation
    \param[in] a quadratic coefficient before x^2
    \param[in] b quadratic coefficient before x
    \param[in] c free term of quadratic equation
    \param[inout] answer1 one of quadratic roots
    \param[inout] answer1 one of quadratic roots
    \return the number of quadratic equation roots
*/
enum NUMBER_OF_SOLUTIONS solve_quadratic_equation (double a, double b, double c, double *answer1, double *answer2);

#endif
