/*
Rewrite the upc.c example so that the user enters 11 digits at one time
instead of entering one digit, then five, and then another five digits
*/

#include <stdio.h>

int main(void)
{
    int upc;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%11d", &upc);

    int j5 = upc % 10;

    upc /= 10;
    int j4 = upc % 10;

    upc /= 10;
    int j3 = upc % 10;

    upc /= 10;
    int j2 = upc % 10;

    upc /= 10;
    int j1 = upc % 10;

    upc /= 10;
    int i5 = upc % 10;

    upc /= 10;
    int i4 = upc % 10;

    upc /= 10;
    int i3 = upc % 10;

    upc /= 10;
    int i2 = upc % 10;

    upc /= 10;
    int i1 = upc % 10;

    upc /= 10;
    int d = upc % 10;

    int first_sum = d + i2 + i4 + j1 + j3 + j5;
    int second_sum = i1 + i3 + i5 + j2 + j4;
    int total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}