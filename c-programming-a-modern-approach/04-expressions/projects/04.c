/*
Display user entered integer in octal
(Chapter 7 will introduce and easier way)
*/

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    int a = n % 8;

    n /= 8;
    int b = n % 8;

    n /= 8;
    int c = n % 8;

    n /= 8;
    int d = n % 8;

    n /= 8;
    int e = n % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", e, d, c, b, a);

    return 0;
}