/*
 * ============================================================================
 *
 *       Filename:  tests.h
 *
 *    Description:  Header file of the test
 *
 *        Created:  24/03/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#ifndef TEST_H
#define TEST_H

#define GREEN "\033[92m"    /**< paint command line text green */  
#define END_COLOR "\x1b[39;49m" /**< paint command line text default color */
#define RED "\033[91m" /**< paint command line text red */

enum TEST_STATE{TEST_SUCCESS, TEST_FAILURE};

void run_default_tests();

int run_tests(const char *file_name);

#endif