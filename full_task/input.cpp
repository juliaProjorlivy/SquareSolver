#include "input.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

void clear_buf(int *is_eof)
{
    char symbol = '0';
    while ((symbol = getchar())!= '\n' && symbol!= EOF)
        ;
    if(symbol == EOF){
       *is_eof = 1;
    }
}

int get_coefficients(double *a, double *b, double *c)
{
    assert(a!=NULL);
    assert(b!=NULL);
    assert(c!=NULL);

    assert(isfinite(*a));
    assert(isfinite(*b));
    assert(isfinite(*c));

    int nCoef = 3;
    int check = scanf("%lf%lf%lf", a, b, c);
    int is_eof = 0;
    while (check != nCoef && check!=EOF)
    {
        clear_buf(&is_eof);
        printf("incorrect input! please, try again.\n");
        check = scanf("%lf%lf%lf", a, b, c);
    }

    return check;
}