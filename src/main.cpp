/*
 * ============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The main file of the project
 *
 *        Created:  24/08/2023 
 *       Compiler:  g++
 * 
 * ============================================================================
 */



#include "input.h"
#include "solve_quadratic_eq.h"

/** 
* include file in case of running the tests
*/
#ifdef RUN_TESTS
#include "test.h"
#endif

#include <stdio.h>
#include <string.h>
#include <math.h>

#define RED "\x1b[31;1m"  /**< paint command line text red */  
#define END_OF_RED "\n\x1b[39;49m"  /**< paint command line default color */  

int main(int argc, char *argv[])
{
    /** 
     * run tests
     */
    #ifdef RUN_TESTS
    if(argc == 2){
        if(!strcmp(argv[1], "--UnitTest")){
            run_tests();
        }
    }  
    #endif // RUN_TESTS
    
    (void) argc;
    (void) argv;
    #ifndef RUN_TESTS
    printf("enter the coefficients separated by spaces:\n");

    double a = 0, b = 0, c = 0;
    int number_of_arg = get_coefficients(&a, &b, &c); ///get the number of coefficients that are successuffully read

    if (number_of_arg == 3)
    {
        printf("%lf %lf %lf\n", a, b, c);

        double answer1 = 0, answer2 = 0;
        int number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);

        switch (number_of_roots) /*various numbers of solutions to a quadtratic equation*/
        {
        case NO_ROOTS:
            printf("no roots\n");
            break;
        case ONE_ROOT:
            printf("the root is:\nx = %lf\n", answer1);
            break;
        case TWO_ROOTS:
            printf("the roots are:\nx1 = %lf\nx2 = %lf\n", answer1, answer2);
            break;
        case INFINITY_SOL:
            printf("infinite number of roots\n");
            break;
        default:
            printf("unexpected number of solutions:%d\n", number_of_roots);
        }
    }
    else
    {
        printf(RED "ERROR: unexpected EOF in string" END_OF_RED);
    }
    #endif
    return 0;
}