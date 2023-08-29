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

void clear_buf();

int get_coefficients (double *a, double *b, double *c);

void print_roots (int number_of_roots, double answer1, double answer2);

#endif
