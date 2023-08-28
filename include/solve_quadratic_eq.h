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

int is_equal(double x, double y, double epsilon = DEF_EPSILON);

int is_less(double x, double y, double epsilon = DEF_EPSILON);

int solve_linear(double b, double c, double *answer1, int number_of_roots);

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2);

#endif
