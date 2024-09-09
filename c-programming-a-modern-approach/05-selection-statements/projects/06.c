/*
Modify the upc.c example from /04 so that it checks whether a UPC is valid.
*/

#include <stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, c,
        first_sum, second_sum, total, check;
    printf("Enter UPC: ");
    scanf("%1d", &d);
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    scanf("%1d", &c);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    check = 9 - ((total - 1) % 10);

    printf("%s\n", check == c ? "VALID" : "INVALID");

    return 0;
}