/*
Write a program that computes the factorial of a positive integer
a) use a short variable, what is the largest value of n for which the program correctly prints the factorial of n?
b) Repear a) using an int
c) Repeat a) using a long
d) Repeat a) using a long long
e) Repeat a) using a float
f) Repeat a) using a double
g) Repeat a) using a long double
*/

#include <limits.h>
#include <stdio.h>

int main(void)
{
    int n = 2;

    printf("\n--------------------\n");
    printf("short\n");
    printf("--------------------\n");
    printf("__SHRT_MAX__: %d\n", __SHRT_MAX__);
    short short_factorial = 1;

    while ((__SHRT_MAX__ - short_factorial) / short_factorial >= n)
    {
        short_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %d\n", n - 1, short_factorial);

    n = 2;

    printf("\n--------------------\n");
    printf("int\n");
    printf("--------------------\n");
    printf("__INT_MAX__: %d\n", __INT_MAX__);
    int int_factorial = 1;

    while ((__INT_MAX__ - int_factorial) / int_factorial >= n)
    {
        int_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %d\n", n - 1, int_factorial);

    n = 2;

    printf("\n--------------------\n");
    printf("long\n");
    printf("--------------------\n");
    printf("__LONG_MAX__: %ld\n", __LONG_MAX__);
    long long_factorial = 1;

    while ((__LONG_MAX__ - long_factorial) / long_factorial >= n)
    {
        long_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %ld\n", n - 1, long_factorial);

    n = 2;

    printf("\n--------------------\n");
    printf("float\n");
    printf("--------------------\n");
    printf("__FLT_MAX__: %f\n", __FLT_MAX__);
    float float_factorial = 1.0f;

    while ((__FLT_MAX__ - float_factorial) / float_factorial >= n)
    {
        float_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %f\n", n - 1, float_factorial);

    n = 2;

    printf("\n--------------------\n");
    printf("double\n");
    printf("--------------------\n");
    printf("__DBL_MAX__: %f\n", __DBL_MAX__);
    double double_factorial = 1.0;

    while ((__DBL_MAX__ - double_factorial) / double_factorial >= n)
    {
        double_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %f\n", n - 1, double_factorial);

    n = 2;

    printf("\n--------------------\n");
    printf("long double\n");
    printf("--------------------\n");
    printf("__LDBL_MAX__: %Lf\n", __LDBL_MAX__);
    long double long_double_factorial = 1.0L;

    while ((__LDBL_MAX__ - long_double_factorial) / long_double_factorial >= n)
    {
        long_double_factorial *= n;
        n++;
    }

    printf("Largest value of n / n!: %d / %Lf\n", n - 1, long_double_factorial);

    return 0;
}