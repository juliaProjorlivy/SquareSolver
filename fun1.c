#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#define EPSILON 1e-9

int is_equal_zero(double x)
{
    return (EPSILON > fabs(x));
}

int solve_linear(double a, double b, double c, double *answer1, int *n)
{
    *n = 1;
    *answer1 = (-1) * c / b;
    return *n;
}

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2, int *n)
{
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        *n = 0;
    }
    else if (is_equal_zero(fabs(a)) && !is_equal_zero(fabs(b)))
    {
        *n = solve_linear(a, b, c, answer1, n);
    }
    else if (is_equal_zero(d))
    {
        *n = 1;
        *answer1 = ((-1) * b / (2 * a));
    }
    else
    {
        *n = 2;
        double sq_d = sqrt(d);
        *answer1 = ((-1) * b + sq_d) / (2 * a);
        *answer2 = ((-1) * b - sq_d) / (2 * a);
    }
    return *n;
}

int get_coefficients(double *a, double *b, double *c)
{
    double coefficients[3];
    char x, number[DBL_DIG] = {'0'};
    int number_of_arg = 0;
    int index = 0;
    x = getchar();
    while (number_of_arg < 3)
    {
        if (isdigit(x))
        {
            number[index] = x;
            index++;
        }
        else if ((isspace(x) || x == '\n') && isdigit(number[index - 1]))
        {
            number[index] = '\0';
            index = 0;
            coefficients[number_of_arg] = atof(number);
            memset(number, '0', DBL_DIG);
            number_of_arg += 1;
            if (x == '\n')
            {
                if (number_of_arg < 3)
                {
                    printf("the number of arguments is less than 3. please, try again:\n");
                    number_of_arg = 0;
                    index = 0;
                    memset(number, '0', DBL_DIG);
                }
                else
                {
                    break;
                }
            }
        }
        else if (x == '-' && index == 0)
        {
            number[index] = x;
            index++;
        }
        else if (x == '.' && isdigit(number[index - 1]))
        {
            number[index] = x;
            index++;
        }
        else
        {
            index = 0;
            memset(number, '0', DBL_DIG);
        }
        x = getchar();
    }
    *a = coefficients[0], *b = coefficients[1], *c = coefficients[2];
    return number_of_arg;
}

int main()
{
    printf("enter the coefficients separated by spaces:\n");
    double a = 0, b = 0, c = 0;
    get_coefficients(&a, &b, &c);
    printf("%lf %lf %lf\n", a, b, c);
    double answer1 = 0, answer2 = 0;
    int n;
    n = solve_quadratic_equation(a, b, c, &answer1, &answer2, &n);
    switch (n)
    {
    case 0:
        printf("no roots");
        break;
    case 1:
        printf("the root is:\nx = %lf\n", answer1);
        break;
    case 2:
        printf("the roots are:\nx1 = %lf\nx2 = %lf", answer1, answer2);
        break;
    }

    return 0;
}
