#ifndef SOLVE_QUADRATIC_EQ_INCLUDED
#define SOLVE_QUADRATIC_EQ_INCLUDED

int is_equal_zero(double x);

int solve_linear(double b, double c, double *answer1, int number_of_roots);

int solve_quadratic_equation(double a, double b, double c, double *answer1, double *answer2);

#endif
