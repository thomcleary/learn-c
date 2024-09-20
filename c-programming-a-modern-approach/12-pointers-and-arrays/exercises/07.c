/*
Write the following function:

bool search(const int a[], int n, int key);

a is an array to be searched, n is the number of elements in the array,
and key is the search key.
search should return true if key matches some element of a,
and false if it doesn't.

Use pointer arithemetic - not subscripting - to visit array elements
*/

#include <stdbool.h>
#include <stdio.h>

bool search(const int a[], int n, int key);

int main(void)
{
    const int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nums_length = sizeof(nums) / sizeof(nums[0]);

    printf("Nums: ");
    for (const int *p = nums; p <= nums + (nums_length - 1); p++)
    {
        printf("%d ", *p);
    }
    printf("\n");

    printf("Contains 5? %s\n", search(nums, nums_length, 5) ? "true" : "false");
    printf("Contains 10? %s\n", search(nums, nums_length, 10) ? "true" : "false");

    return 0;
}

bool search(const int a[], int n, int key)
{
    for (const int *p = a; p <= a + (n - 1); p++)
    {
        if (*p == key)
        {
            return true;
        }
    }

    return false;
}
