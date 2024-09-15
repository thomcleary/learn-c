/*
Write a program that asks the user to enter values for x and n
Write a recursive function power() to compute x^n
*/

#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("x to the power n: %d\n", power(x, n));

    return 0;
}

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        int i = power(x, n / 2);
        return i * i;
    }

    return x * power(x, n - 1);
}