#include "solve_quadratic_eq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GREEN "\033[92m"
#define END "\x1b[39;49m"
#define RED "\033[91m"



double rounding(double x, int n){
    double power_ten1 = pow(10, (n+1));
    double power_ten2 = pow(10, (n));
    double power_ten3 = pow(10, (-n));
    int last_digit = (((int)(x*power_ten1)) % 10 >=5) ? 1:0;
    return power_ten3*((int)(x*power_ten2) + last_digit);
}



void test_square(const test *data){
    double answer1 = 0, answer2 = 0;
    int nRoots = solve_quadratic_equation(data->abc[0], data->abc[1], data->abc[2], &answer1, &answer2);
    answer1 = rounding(answer1, 5);
    answer2 = rounding(answer2, 5);


    if(!is_equal(answer1, data->answersRef[0]) || !is_equal(answer2, data->answersRef[1]) || nRoots!=(data->nRootsRef))
    {
        printf(RED "test case failed:\n" END);
        printf("x1 = %lf; x2 = %lf; nRoots = %d\n"
        "expected:\nx1 = %lf; x2 = %lf; nRoots = %d\n ", answer1, answer2,
        nRoots, data->answersRef[0], data->answersRef[1], data->nRootsRef);
    }
    else
    {
        printf(GREEN "test case passed successully\n" END);
    }
}


void run_tests()
{
    test tests[] = {{{5, 10, -15}, {1, -3}, 2}, 
                    {{0, 0, 0}, {0, 0}, 3}, 
                    {{1.3, 1.54, -15}, {2.85578, -4.04039}, 2}, 
                    {{0, 1, 0}, {0, 0}, 1}, 
                    {{1.9, -2.1, -6}, {2.41362, -1.30836}, 2}};
    size_t length = sizeof(tests)/sizeof(tests[0]);
    for(int index = 0; index < (int)length; index++){
        printf(GREEN "%d " END, index + 1);
        test_square(&tests[index]);
    }
}
