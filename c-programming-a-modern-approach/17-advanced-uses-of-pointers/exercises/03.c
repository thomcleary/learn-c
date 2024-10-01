/*
Write the following function:

int *create_array(int n, int initial_value);

The function should return a pointer to a dynamically allocated int array with n members,
each of which is initialized to initial_value.
The return values should be NULL if the array can't be allocated.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 12
#define INITIAL_VALUE 69

int *create_array(int n, int initial_value)
{
    // Should just use malloc, but Section 17.3 introduced calloc, so what the hell...
    int *a = calloc(n, sizeof(int));

    if (a == NULL)
    {
        return a;
    }

    for (int *i = a; i < a + n; i++)
    {
        *i = initial_value;
    }

    return a;
}

int main(void)
{
    int *nums = create_array(N, INITIAL_VALUE);

    printf("[-1]: %d\n", *(nums - 1));

    for (int i = 0; i < N; i++)
    {
        printf("[%d]: %d\n", i, nums[i]);
    }

    printf("[%d]: %d\n", N, *(nums + N));

    free(nums);

    return 0;
}