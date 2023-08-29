/* ============================================================================
 *
 *       Filename:  input.h
 *
 *    Description:  Header file for the input function
 *
 *        Created:  24/03/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#ifndef INPUT_H
#define INPUT_H
#include "test.h"
#include "solve_quadratic_eq.h"

/*!
    \brief runs test if user demands this via command line arguments key
    \param[in] argc the number of arguments
    \param[in] argv command line arguments
    \return 
*/
enum TEST_STATE whether_to_run_tests(int argc, const char *argv[]);

/*!
    \brief Clears the input buffer
*/
void clear_buf();

/*!
    \brief Reads input data and in case of an incorrect input asks user to type again
    \param[inout] a quadratic coefficient before x^2
    \param[inout] b quadratic coefficient before x
    \param[inout] c free term of quadratic equation
    \return the number of parametrs that were read

*/
int get_coefficients(double *a, double *b, double *c);

/*!
    \brief prints the answers to the quadratic equation
*/
void print_roots(enum NUMBER_OF_SOLUTIONS number_of_roots, double answer1, double answer2);

#endif
