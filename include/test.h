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

/**
 * For comfortable usage of 1 and 0 in return
 */
enum TEST_STATE 
{
    FTEST_SUCCESS, 
    FTEST_FAILURE,
    TESTS_NO_LAUNCH
};

/**
 * Run default tests
 */
void run_default_tests();

/**
 * Run tests from the file. Takes the file name.
 * \param[in] file_name the name of the file
 */
int run_file_tests (const char *file_name);

#endif
