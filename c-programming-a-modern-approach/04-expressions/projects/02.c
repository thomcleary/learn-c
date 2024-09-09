#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a three-digit number: ");
    scanf("%3d", &n);

    int last_two_digits = n % 100;

    printf("The reversal is: %d%d%d\n", last_two_digits % 10, last_two_digits / 10, n / 100);

    return 0;
}