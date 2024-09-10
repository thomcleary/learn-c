/*
Write a program that asks the user to enter two integers
then calculates and displays their greatest common divisor (GCD)
*/

#include <stdio.h>

int main(void)
{
    int m, n;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}