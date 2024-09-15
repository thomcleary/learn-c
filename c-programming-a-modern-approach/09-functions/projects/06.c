/*
Write a function that computes the value of the following polynomial

3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

Write a program that asks the user to enter a value for x,
calls the function to compute the value of the polynomial,
and then displays the value returned by the function
*/

#include <stdio.h>
#include <math.h>

double calculate_polynomial(double x);

int main(void)
{
    double x;

    printf("Enter value of x: ");
    scanf("%lf", &x);

    printf("Value of x is: %lf\n", calculate_polynomial(x));

    return 0;
}

double calculate_polynomial(double x)
{
    return (
        (3 * pow(x, 5.0)) +
        (2 * pow(x, 4.0)) -
        (5 * pow(x, 3.0)) -
        (pow(x, 2.0)) +
        (7 * x) -
        6);
}
