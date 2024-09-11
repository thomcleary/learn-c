/*
Write a program that uses Newton's method to compute the sqaure root of a positive floating point number
Use double rather than float for greater accuracy
Have the program terminate when the absolute value of the difference between
the old value of y and the new value of y is less than the product of
0.00001 and y

(call the fabs function to find the absolute value of a double, include <math.h>)
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
    double x, y = 1.0;
    double prev_y = 0;

    printf("Enter a positive number: ");
    scanf(" %lf", &x);

    if (x < 0)
    {
        printf("The number must be positive.\n");
        return 0;
    }

    while (fabs(y - prev_y) >= (0.00001 * y))
    {
        prev_y = y;
        y = (y + (x / y)) / 2;
    }

    printf("Square root: %f\n", y);

    return 0;
}