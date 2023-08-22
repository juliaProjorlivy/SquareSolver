#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#define RED "\x1b[31;1m"
#define END_OF_RED "\n\x1b[39;49m"

enum NUMBER_OF_SOLUTIONS
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITY_SOL = 3
};


int is_equal_zero(double x)
{
    const double EPSILON = 1e-9;
    return (fabs(x) < EPSILON);
}

int solve_linear(double b, double c, double *answer1, int number_of_roots)
{
    if(!is_equal_zero(c))
    {
        number_of_roots = is_equal_zero(b) ? NO_ROOTS : ONE_ROOT;
    }
    else
    {
        number_of_roots = is_equal_zero(b) ? INFINITY_SOL : ONE_ROOT;
    }
    double value = (-1) * c / b;
    *answer1 = (is_equal_zero(b) || is_equal_zero(value)) ? 0 : value;
    return number_of_roots;
}

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2)
{
    int number_of_roots = 0;
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        return 0;
    }
    if (is_equal_zero(a))
    {
        return (solve_linear(b, c, answer1, number_of_roots));
    }
    if (is_equal_zero(d))
    {
        *answer1 = ((-1) * b / (2 * a));
        return 1;
    }
    else
    {
        double sq_d = sqrt(d);
        *answer1 = ((-1) * b + sq_d) / (2 * a);
        *answer2 = ((-1) * b - sq_d) / (2 * a);
        return 2;
    }
}

void clear_buf(int *flag)
{
    char symbol = '0';
    while ((symbol = getchar())!= '\n' && symbol!= EOF)
        ;
    if(symbol == EOF){
       *flag = 1;
    }
}

int get_coefficients(double *a, double *b, double *c)
{
    int check = scanf("%lf%lf%lf", a, b, c);

    while (check != 3)
    {
        int flag = 0;
        clear_buf(&flag);

        if(flag)
        {
            break;
        }

        printf("incorrect entrance! please, try again.\n");
        check = scanf("%lf%lf%lf", a, b, c);
    }

    return check;
}


void test_square(double a, double b, double c, double right_answer1, double right_answer2){
    double answer1 = 0, answer2 = 0;
    int number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);
    if(((right_answer1 == answer2) || (right_answer1 == answer1)) && ((right_answer2 == answer2) || (right_answer2 == answer1)))
    {
        printf("test case successfully passed\n");
    }
    else
    {
        printf("test case faild\n");
    }
}

void run_tests(){
    int nTests = 5;
    double coef[nTests][3] = {{5, 10, -15}, {1.8, 9, -0}, {1.55, -6.3, 8}, {0, 1, 0}, {2, 0, -24.5}};
    double right_answers[nTests][2] = {{-3, 1}, {-5, 0}, {0, 0}, {0, 0}, {-3.5, 3.5}};
    for(int index = 0; index<nTests; index++){
        printf("%d ", index+1);
        test_square(coef[index][0], coef[index][1], coef[index][2], right_answers[index][0], right_answers[index][1]);
    }
}

int main()
{
    run_tests();

    printf("enter the coefficients separated by spaces:\n");

    double a = 0, b = 0, c = 0;
    int number_of_arg = get_coefficients(&a, &b, &c);

    if (number_of_arg == 3)
    {
        printf("%lf %lf %lf\n", a, b, c);

        double answer1 = 0, answer2 = 0;
        int number_of_roots;
        number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);

        switch (number_of_roots)
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
        }
    }
    else
    {
        printf(RED "ERROR: unexpected EOF in string" END_OF_RED);
    }

    return 0;
}
