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

/*!
    \brief Clears the input buffer
    \param is_eof indicate the EOF
*/
void clear_buf();

/*!
    \brief Reads input data and in case of an incorrect input asks user to type again
    \param[inout] a quadratic coefficient before x^2
    \param[inout] b quadratic coefficient before x
    \param[inout] c free term of quadratic equation
    \return the number of parametrs that were read

*/
int get_coefficients (double *a, double *b, double *c);

/*!
    \brief prints the answers to the quadratic equation
    \param is_eof indicate the EOF
*/
void print_roots (int number_of_roots, double answer1, double answer2);

#endif
