#ifndef SOLVE_QUADRATIC_EQ_INCLUDED
#define SOLVE_QUADRATIC_EQ_INCLUDED
enum NUMBER_OF_SOLUTIONS
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINITY_SOL = 3
};

int is_equal(double x, double y);

int solve_linear(double b, double c, double *answer1, int number_of_roots);

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2);

#endif
