/*
Rewrite 02.c so that it prints the reversal of a three-digit number
without using arithemtic to split the numbers into digits
*/

#include <stdio.h>

int main(void)
{
    int a, b, c;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &a, &b, &c);

    printf("The reversal is: %d%d%d\n", c, b, a);

    return 0;
}