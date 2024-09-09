/*
Write a program that calculates how many digits a number contains
(You may assume the number has no more than 4 digits)
*/

#include <stdio.h>

int main(void)
{
    int n, digits;

    printf("Enter a number: ");
    scanf("%3d", &n);

    if (n < 10)
    {
        digits = 1;
    }
    else if (n < 100)
    {
        digits = 2;
    }
    else if (n < 1000)
    {
        digits = 3;
    }
    else
    {
        digits = 4;
    }

    printf("The number %d has %d %s\n", n, digits, digits > 1 ? "digits" : "digit");

    return 0;
}