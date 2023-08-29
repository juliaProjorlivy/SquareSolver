#include "solve_quadratic_eq.h"
#include <assert.h>
#include <math.h>

int is_equal(double x, double y, double epsilon)
{
    assert (isfinite (x));
    assert (isfinite (y));
    assert (isfinite (epsilon));

    return (fabs (x - y) < epsilon);
}

int is_less (double x, double y, double epsilon)
{
    assert (isfinite (x));
    assert (isfinite (y));
    assert (isfinite (epsilon));
    
    return ((x - y < (-1) * epsilon));
}

enum NUMBER_OF_SOLUTIONS solve_linear_equation (double b, double c, double *answer1)
{
    assert (isfinite (b));
    assert (isfinite (c));
    assert (answer1 != NULL);

    double value = 0;
    enum NUMBER_OF_SOLUTIONS number_of_roots = NO_ROOTS;

    if (!is_equal (b, 0))
    {
        value = (-1) * c / b;
        number_of_roots = ONE_ROOT;
    }
    else
    {
        number_of_roots = is_equal (c, 0) ? INFINITY_SOL : NO_ROOTS;
    }
    *answer1 = (is_equal (b, 0) || is_equal (value, 0)) ? 0 : value;
    return number_of_roots;
}

enum NUMBER_OF_SOLUTIONS solve_quadratic_equation (double a, double b, double c, double *answer1, double *answer2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (answer1 != NULL);
    assert (answer2 != NULL);

    double d = b * b - 4 * a * c;

    if (is_less (d, 0))
    {
        return NO_ROOTS;
    }
    if (is_equal (a, 0))
    {
        return (solve_linear_equation (b, c, answer1));
    }
    if (is_equal (d, 0))
    {
        *answer1 = ((-1) * b / (2 * a));
        return ONE_ROOT;
    }
    else
    {
        double sq_d = sqrt (d);
        *answer1 = ((-1) * b + sq_d) / (2 * a);
        *answer2 = ((-1) * b - sq_d) / (2 * a);
        return TWO_ROOTS;
    }
}
