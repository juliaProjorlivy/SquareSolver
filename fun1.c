#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

int comparison(double x)
{
    long double compare_number = 1e-9;
    return (compare_number - x) > 0 ? 1 : 0;
}

int solve(double a, double b, double c, double *answer1, double *answer2, int *n)
{
    long double compare_number = 1e-9;
    double d = b * b - 4 * a * c;
    if (comparison(fabs(a)) && !comparison(fabs(b)))
    {
        *n = 1;
        *answer1 = (-1) * c / b;
    }
    else if (comparison(d))
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
    return 0;
}

int main()
{
    printf("enter the coefficients separated by spaces:\n");
    double coefficients[3];
    char x, number[DBL_DIG];
    int number_of_coefficients = 0;
    int i = 0;
    while ((x = getchar()) && number_of_coefficients < 3)
    {
        if (isdigit(x))
        {
            number[i] = x;
            i++;
        }
        else if ((isspace(x) || x == '\n') && isdigit(number[i - 1]))
        {
            number[i] = '\0';
            i = 0;
            coefficients[number_of_coefficients] = atof(number);
            memset(number, '0', 11);
            number_of_coefficients++;
            if (x == '\n')
            {
                break;
            }
        }
        else if (x == '-' && i == 0)
        {
            number[i] = x;
            i++;
        }
        else if (x == '.' && isdigit(number[i - 1]))
        {
            number[i] = x;
            i++;
        }
        else
        {
            i = 0;
            memset(number, '0', DBL_DIG);
        }
    }
    double a = coefficients[0], b = coefficients[1], c = coefficients[2];
    printf("%lf %lf %lf\n", a, b, c);
    if (comparison((b * b - 4 * a * c)))
    {
        printf("no roots\n");
    }
    else
    {
        double answer1, answer2;
        int n;
        solve(a, b, c, &answer1, &answer2, &n);
        n == 2 ? printf("the roots are:\nx1 = %lf\nx2 = %lf", answer1, answer2) : printf("the root is:\nx = %lf\n", answer1);
    }
    return 0;
}
