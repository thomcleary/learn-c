/*
Write a program that asks the user to enter a series of integers (which it stores in an array)
Then sorts te integers by calling the function selection_sort
When given an array with n elements, selection_sort must do the following
1. Search the array to find the largest element, then move it to the last position in the array
2. Call itself recursively to sort the first n - 1 elements of the array
*/

#include <stdio.h>

#define MAX_NUMS 128

int get_nums(int length, int nums[length]);
void selection_sort(int length, int arr[length]);
void print_nums(int length, int arr[length]);

int main(void)
{
    int nums[MAX_NUMS];

    int nums_entered = get_nums(MAX_NUMS, nums);
    selection_sort(nums_entered, nums);
    print_nums(nums_entered, nums);

    return 0;
}

int get_nums(int length, int nums[length])
{
    int n = 0;

    printf("Enter integers to be sorted: ");

    while (n < MAX_NUMS)
    {
        scanf("%d", &nums[n++]);

        char next;
        while ((next = getchar()) == ' ')
        {
            ;
        }

        if (next == '\n')
        {
            break;
        }
        ungetc(next, stdin);
    }

    return n;
}

void selection_sort(int length, int nums[length])
{
    if (length == 1)
    {
        return;
    }

    int high_pos = 0;

    for (int i = 1; i < length; i++)
    {
        int n = nums[i];
        if (n > nums[high_pos])
        {
            high_pos = i;
        }
    }

    int num_to_swap = nums[length - 1];
    nums[length - 1] = nums[high_pos];
    nums[high_pos] = num_to_swap;

    selection_sort(length - 1, nums);
}

void print_nums(int length, int arr[length])
{
    printf("In sorted order:");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
