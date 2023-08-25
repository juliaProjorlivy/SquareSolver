/*
 * ============================================================================
 *
 *       Filename:  tests.h
 *
 *    Description:  Header file for test
 *
 *        Created:  24/03/2023
 *       Compiler:  g++
 *
 * ============================================================================
 */

#ifndef TEST_H
#define TEST_H

#define GREEN "\033[92m"    /**< paint command line text green */  

enum TEST_STATE {FTEST_SUCCESS, FTEST_FAILURE};

void run_default_tests();

int run_tests (const char *file_name);

#endif
