/*
Rewrite the following function to use pointer arithmetic instead of array subscripting.

int sum_array(const int a[], int n)
{
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
*/

#include <stdio.h>

int sum_array(const int a[], int n);

int main(void)
{
    const int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Sum: %d\n", sum_array(nums, sizeof(nums) / sizeof(nums[0])));

    return 0;
}

int sum_array(const int a[], int n)
{
    const int *i;
    int sum = 0;

    for (i = a; i <= &a[n - 1]; i++)
        sum += *i;

    return sum;
}