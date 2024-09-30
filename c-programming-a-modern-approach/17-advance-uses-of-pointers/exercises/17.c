/*
Let a be an array of 100 integers.
Write a call of qsort that sorts only the last 50 elements in a.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A_LEN 100

int rand_int(int max)
{
    return (rand() % max) + 1;
}

void print_nums(int nums[A_LEN])
{
    printf("[\n");
    for (int i = 0; i < A_LEN; i++)
    {
        printf("%d", nums[i]);
        if (i + 1 < A_LEN)
        {
            printf(", ");
        }
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("]\n");
}

int compare_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    srand(time(NULL));

    int a[A_LEN] = {0};

    for (int i = 0; i < A_LEN; i++)
    {
        a[i] = rand_int(A_LEN);
    }

    printf("Before\n");
    print_nums(a);

    qsort(a + 50, 50, sizeof(*a), compare_int);

    printf("\nAfter\n");
    print_nums(a);

    return 0;
}