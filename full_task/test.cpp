#include "solve_quadratic_eq.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rounding(double x, int n){
    double power_ten1 = pow(10, (n+1));
    double power_ten2 = pow(10, (n));
    double power_ten3 = pow(10, (-n));
    int last_digit = (((int)(x*power_ten1)) % 10 >=5) ? 1:0;
    return power_ten3*((int)(x*power_ten2) + last_digit);
}


struct test{
    double abc[3];
    double answersRef[2];
    int nRootsRef;
};
typedef struct test test;

void test_square(test *data){
    double answer1 = 0, answer2 = 0;
    int nRoots = solve_quadratic_equation((data->abc)[0], (data->abc)[1], (data->abc)[2], &answer1, &answer2);
    printf("a = %lf\n", (data->abc)[0]);
    // answer1 = rounding(answer1, 5);
    // answer2 = rounding(answer2, 5);

    if(answer1!=((data->answersRef)[0]) || answer2!=((data->answersRef)[1]) || nRoots!=(data->nRootsRef))
    {
        printf("test case failed:\nx1 = %lf; x2 = %lf; nRoots = %d\n"
        "expected:\nx1 = %lf; x2 = %lf; nRoots = %d\n ", answer1, answer2,
        nRoots, (data->answersRef)[0], (data->answersRef)[1], data->nRootsRef);
    }
    else
    {
        printf("test case passed successully\n");
    }
}


void run_tests()
{
//{.abc = {}, .answersRef = {}, .nRootsRef = 0 };
    struct test tests[] = {.abc = {}, .answersRef = {}, .nRootsRef = 0 };
    struct test *tests = &tests;
    testss->abc = {5, 10, -15};
    testss->answersRef = {1, -1};
    testss->nRootsRef = 2;
    test_square(testss);
    // size_t length = sizeof(tests)/sizeof(tests[0]);
    // for(int index = 1; index <= (int)length; index++){
    //     printf("%d ", index);
    //     test_square(tests);
    // }
}
//  {{1.3, 1.54, -15}, {2.85578, -4.04039}, 2},
//{{0, 0, 0}, {0, 0}, 3}