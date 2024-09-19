/*
Write the following function:

void swap(int *p, int *q);

When passed the addresses of two variables, swap should exchange the values of the variables
*/

#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
    int a = 4, b = 2;

    printf("Before swap: a=%d, b=%d\n", a, b);

    swap(&a, &b);

    printf("After swap: a=%d, b=%d\n", a, b);

    return 0;
}

void swap(int *p, int *q)
{
    int temp = *q;
    *q = *p;
    *p = temp;
}