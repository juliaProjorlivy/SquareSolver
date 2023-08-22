#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <assert.h>

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
    while ((symbol = getchar())!= '\n' && symbol!='\x1a')
        ;
    if(symbol == '\x1a'){
       *flag = 1;
    }
}

int get_coefficients(double *a, double *b, double *c)
{
    int check = scanf("%lf%lf%lf", a, b, c);

    while (check!= EOF && check != 3)
    {
        int flag = 0;
        clear_buf(&flag);

        if(flag)
        {
            break;
        }

        printf("it is not a digit! please, try again.\n");
        check = scanf("%lf%lf%lf", a, b, c);
    }

    return check;
}

// int get_coefficients(double *a, double *b, double *c)
// {
//     assert(a != NULL);
//     assert(b != NULL);
//     assert(c != NULL);

//     double coefficients[3] = {0, 0, 0};
//     char number_buf[DBL_DIG] = {'\0'};
//     char symbol = '0';
//     int number_of_arg = 0;
//     int index = 0, nothing_before_digit = 1;
//     // while(getchar() != '\n')
//     // scanf
//     while (((symbol = getchar()) != EOF) && (number_of_arg < 3))
//     {
//         if (isdigit(symbol) && nothing_before_digit)
//         {
//             number_buf[index] = symbol;
//             index++;
//         }
//         else if ((isspace(symbol)))
//         {
//             nothing_before_digit = 1;
//             if (isdigit(number_buf[index - 1]) || isspace(number_buf[index - 1]))
//             {
//                 number_buf[index] = '\0';
//                 index = 0;
//                 coefficients[number_of_arg] = atof(number_buf);
//                 memset(number_buf, '0', DBL_DIG);
//                 number_of_arg += 1;
//             }
//             if (symbol == '\n')
//             {
//                 if (number_of_arg < 3)
//                 {
//                     printf("the number of arguments is less than 3. please, try again:\n");
//                     number_of_arg = 0;
//                     index = 0;
//                     memset(number_buf, '0', DBL_DIG);
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }

//             else
//             {
//                 index = 0;
//                 memset(number_buf, '0', DBL_DIG);
//             }
//         }
//         else if (symbol == '-' && index == 0)
//         {
//             number_buf[index] = symbol;
//             index++;
//         }
//         else if (symbol == '.' && isdigit(number_buf[index - 1]))
//         {
//             number_buf[index] = symbol;
//             index++;
//         }
//         else
//         {
//             nothing_before_digit = 0;
//             index = 0;
//             memset(number_buf, '0', DBL_DIG);
//         }
//     }
//     *a = coefficients[0], *b = coefficients[1], *c = coefficients[2];
//     return number_of_arg;
// }

int main()
{
    printf("enter the coefficients separated by spaces:\n");

    double a = 0, b = 0, c = 0;
    int number_of_arg = get_coefficients(&a, &b, &c);

    if (number_of_arg == 3)
    {
        printf("%lf %lf %lf\n", a, b, c);

        double answer1 = 0, answer2 = 0;
        int number_of_roots;
        number_of_roots = solve_quadratic_equation(a, b, c, &answer1, &answer2);
        // test_square( 1, 2, 1, -1, -1)
        // run_tests()

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
        printf("ERROR: unexpected EOF in string");
    }

    return 0;
}
