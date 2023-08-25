/*
 * ============================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  Run tests
 *
 *        Created:  24/08/2023 
 *       Compiler:  g++
 * 
 * ============================================================================
 */


#include "solve_quadratic_eq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdlib.h>

#define GREEN "\033[92m"    /**< paint command line text green */  
#define END_COLOR "\x1b[39;49m" /**< paint command line text default color */
#define RED "\033[91m" /**< paint command line text red */


/*!

	\brief  data template for tests
    
*/
struct test{
    double abc[3];
    double answersRef[2];
    int nRootsRef;
};


/*!
	\brief test sovle_quadratic_equation function 
    \param[inout] data the test structure 
    \return 1 test passed successfully and 0 if not
    
*/
static int test_square(const test *data, int index){
    int success = 0;
    const double EPSILON2 = 1e-5; /**< the equivalent number */ 
    double answer1 = 0, answer2 = 0;
    int nRoots = solve_quadratic_equation(data->abc[0], data->abc[1], data->abc[2], &answer1, &answer2);

    if(!is_equal(answer1, data->answersRef[0], EPSILON2) || !is_equal(answer2, data->answersRef[1], EPSILON2) || nRoots!=(data->nRootsRef))
    {
        printf(RED "%d test case failed:\n" END_COLOR, index);
        printf("x1 = %lf; x2 = %lf; nRoots = %d\n"
                "expected:\nx1 = %lf; x2 = %lf; nRoots = %d\n ", answer1, answer2,
                nRoots, data->answersRef[0], data->answersRef[1], data->nRootsRef);
    }
    else
    {
        success = 1;
        printf(GREEN "%d test case passed successully\n" END_COLOR, index);
    }
    return success;
}


/**
 * Test runner function
 */
// void run_tests()
// {
// //                    a   b    c    x1  x2  nRoots
//     test tests[] = {{{5, 10, -15}, {1, -3}, 2}, 
//                     {{0,  0,   0}, {0,  0}, 3}, 
//                     {{1.3, 1.54, -15}, {2.85578, -4.04039}, 2}, 
//                     {{0, 1, 0}, {0, 0}, 1}, 
//                     {{1.9, -2.1, -6}, {2.41362, -1.30836}, 2}};
//     size_t length = sizeof(tests)/sizeof(tests[0]);
//     for(int index = 0; index < (int)length; index++){
//         test_square(&tests[index], index+1);
//     }
// }


void run_tests()
{
    const int nTests = 4;
    
    test tests[nTests] = {{{0, 0, 0}, {0, 0}, 0}};

    FILE *file = fopen("data_tests.txt", "r");

    int index = 0;
    while((fscanf(file, "%lf%lf%lf%lf%lf%d", &(tests[index].abc[0]), &(tests[index].abc[1]), 
            &(tests[index].abc[2]),&(tests[index].answersRef[0]), &(tests[index].answersRef[1]), 
            &(tests[index].nRootsRef))) == 6){

        index++;

        if(index>nTests){
            break;
        }
        
    }
    
    for(int i = 0; i < nTests; i++){
        test_square(&tests[i], i+1);
    }
}
