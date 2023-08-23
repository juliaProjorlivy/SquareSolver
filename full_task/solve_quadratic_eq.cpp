#include "solve_quadratic_eq.h"
#include <math.h>

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
    double value = 0;
    if(!is_equal_zero(b))
    {
        value = (-1) * c / b;
        number_of_roots =  ONE_ROOT;
    }
    else
    {
        number_of_roots = is_equal_zero(c) ? INFINITY_SOL : NO_ROOTS;
    }
    *answer1 = (is_equal_zero(b) || is_equal_zero(value)) ? 0 : value;
    return number_of_roots;
}

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2)
{
    int number_of_roots = 0;
    double d = b * b - 4 * a * c;
    if (d<0)
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
