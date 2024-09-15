/*
Modify the reverse.c example to use the expression
(int) (sizeof(a)) / sizeof(a[0])) for the array length
*/

#include <stdio.h>

#define N 10
#define A_LENGTH (int)(sizeof(a) / sizeof(a[0]))

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers: ", N);
    for (i = 0; i < A_LENGTH; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = A_LENGTH - 1; i >= 0; i--)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}