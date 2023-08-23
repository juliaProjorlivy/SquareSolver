#include "main.h"
#include "input.h"
#include "solve_quadratic_eq.h"
#include "test.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

#define RED "\x1b[31;1m"
#define END_OF_RED "\n\x1b[39;49m"


int main(int argc, char *argv[])
{
    if(argc == 2){
        if(!strcmp(argv[1], "--UnitTest")){
            run_tests();
        }
    }

    printf("enter the coefficients separated by spaces:\n");

    double a = 0, b = 0, c = 0;
    int number_of_arg = get_coefficients(&a, &b, &c);

    if (number_of_arg == 3)
    {
        printf("%lf %lf %lf\n", a, b, c);

        double answer1 = 0, answer2 = 0;
        int number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);

        switch (number_of_roots)
        {
        case 0:
            printf("no roots\n");
            break;
        case 1:
            printf("the root is:\nx = %lf\n", answer1);
            break;
        case 2:
            printf("the roots are:\nx1 = %lf\nx2 = %lf\n", answer1, answer2);
            break;
        case 3:
            printf("infinite number of roots\n");
            break;
        }
    }
    else
    {
        printf(RED "ERROR: unexpected EOF in string" END_OF_RED);
    }

    return 0;
}