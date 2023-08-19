#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve(double a, double b, double c, double *answer, int *n)
{
    long double compare_number = 1e-9;
    double d = b * b - 4 * a * c;
    if (d < compare_number)
    {
        answer = (double *)realloc(answer, sizeof(double) * 1);
        *n = 1;
        answer[0] = ((-1) * b / (2 * a));
    }
    else
    {
        *n = 2;
        double sq_d = sqrt(d);
        answer[0] = ((-1) * b + sq_d) / (2 * a);
        answer[1] = ((-1) * b - sq_d) / (2 * a);
    }
}

int main()
{
    long double compare_number = 1e-9;
    double a, b, c;
    int check, n;
    printf("enter the coefficients\n");
    while ((check = scanf("%lf%lf%lf", &a, &b, &c)) != 3)
    {
        printf("it is not a digit! please, try again.\n");
        fflush(stdin);
    }
    if (fabs(a) < compare_number)
    {
        printf("it's not a quadratic equation\n");
    }
    else
    {
        if ((b * b - 4 * a * c) < compare_number)
        {
            printf("no roots\n");
        }
        else
        {
            printf("the roots are:\n");
            double *answer = (double *)malloc(sizeof(double) * 2);
            solve(a, b, c, answer, &n);
            for (int i = 0; i < n; i++)
            {
                printf("x%d = %lf\n", i + 1, answer[i]);
            }
            free(answer);
        }
    }
    return 0;
}
