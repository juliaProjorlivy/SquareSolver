#include <stdio.h>
#include <ctype.h>
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
    double a, b, c;
    int check;
    printf("enter the coefficients\n");
    while ((check = scanf("%lf%lf%lf", &a, &b, &c)) != 3)
    {
        printf("it is not a digit! please, try again.\n");
        fflush(stdin);
    }
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
