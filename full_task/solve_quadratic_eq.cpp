#include "solve_quadratic_eq.h"
#include <assert.h>
#include <math.h>

int is_equal(double x, double y, double epsilon)
{
    assert(isfinite(x));
    assert(isfinite(y));
    
    return (fabs(x - y) < epsilon);
    
}

int solve_linear(double b, double c, double *answer1, int number_of_roots)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(isfinite(number_of_roots));
    assert(answer1!=NULL);

    double value = 0;
    if(!is_equal(b, 0))
    {
        value = (-1) * c / b;
        number_of_roots =  ONE_ROOT;
    }
    else
    {
        number_of_roots = is_equal(c, 0) ? INFINITY_SOL : NO_ROOTS;
    }
    *answer1 = (is_equal(b, 0) || is_equal(value, 0)) ? 0 : value;
    return number_of_roots;
}

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(answer1!=NULL);
    assert(answer2!=NULL);

    int number_of_roots = 0;
    double d = b * b - 4 * a * c;
    if (d<0)
    {
        return 0;
    }
    if (is_equal(a, 0))
    {
        return (solve_linear(b, c, answer1, number_of_roots));
    }
    if (is_equal(d, 0))
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
