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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
static int test_square(const test *data){
    int success = 0;
    const double EPSILON2 = 1e-5; /**< the equivalent number */ 
    double answer1 = 0, answer2 = 0;
    int nRoots = solve_quadratic_equation(data->abc[0], data->abc[1], data->abc[2], &answer1, &answer2);

    if(!is_equal(answer1, data->answersRef[0], EPSILON2) || !is_equal(answer2, data->answersRef[1], EPSILON2) || nRoots!=(data->nRootsRef))
    {
        printf(RED "test case failed:\n" END_COLOR);
        printf("x1 = %lf; x2 = %lf; nRoots = %d\n"
                "expected:\nx1 = %lf; x2 = %lf; nRoots = %d\n ", answer1, answer2,
                nRoots, data->answersRef[0], data->answersRef[1], data->nRootsRef);
    }
    else
    {
        success = 1;
        printf(GREEN "test case passed successully\n" END_COLOR);
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
    test test_data = {};
//     struct stat filestat = {};
//     stat("data_tests.txt", &filestat);

//     char *tests = (char *)calloc(filestat.st_size, sizeof(char));

    FILE *file = fopen("data_tests.txt", "r");

//     if(fread(tests, sizeof(char), filestat.st_size, file) != filestat.st_size){
//         printf("error\n");
//     } 
// // stat(file) -> calloc
// // file -> buff
// // sscanf(buff) -> struct test
// // test(struct test)


    while((fscanf(file, "%lf %lf %lf %lf %lf %d", test_data.abc, test_data.abc + 1, 
            test_data.abc + 2, test_data.answersRef, test_data.answersRef + 1, 
            &(test_data.nRootsRef)) == 6)){
            
            test_square(&test_data);
        }
    

    fclose(file);

}
