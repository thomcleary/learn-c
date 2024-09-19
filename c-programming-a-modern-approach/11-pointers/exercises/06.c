/*
Write the following function:

void find_two_largest(int a[], int n, int *largest, int *second_largest);

When passed an array of length n, the function will search a for its largest and second largest elements,
storing them in the variables pointed to by largest and second_largest respectively
*/

#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
    int nums[] = {7, 4, 3, 8, 6, 5, 9, 2, 1};
    int largest, second_largest;

    find_two_largest(nums, (int)(sizeof(nums) / sizeof(nums[0])), &largest, &second_largest);

    printf("Largest: %d\n", largest);
    printf("Second largest: %d\n", second_largest);

    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    *largest = *second_largest = a[0];

    for (int i = 1; i < n; i++)
    {
        int num = a[i];

        if (num > *largest)
        {
            *second_largest = *largest;
            *largest = num;
        }
        else if (num > *second_largest)
        {
            *second_largest = num;
        }
    }
}
