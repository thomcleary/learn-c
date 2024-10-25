/*
Write a program that reads integers from a text file whose name is given as a command-line
argument.

Each line of the file may contain any number of integers (including none)
separated by one or more spaces.

Have the program display:
- the largest number in the file
- the smallest number
- the median

If the file contains an even number of integers, there will be two numbers in the
middle; the program should display their average (rounded down).

You may assume that the file contains no more than 10_000 integers.

Hint: Store some integers in an array and then sort the array
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

struct Stats
{
    int min, max, median;
};

struct Stats stats(int nums[MAX_NUMS], size_t length);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "usage: ./18 filename\n");
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int nums[MAX_NUMS];
    unsigned int count = 0;

    int num;
    while (fscanf(fp, " %d", &num) == 1)
    {
        if (count < MAX_NUMS)
        {
            nums[count++] = num;
        }
        else
        {
            fclose(fp);
            fprintf(stderr, "File %s contains to many numbers\n", filename);
            exit(EXIT_FAILURE);
        }
    }

    bool read_error = ferror(fp);
    fclose(fp);

    if (read_error)
    {
        fprintf(stderr, "Failed to read from input file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    struct Stats s = stats(nums, count);
    printf("min: %d\nmax: %d\nmedian: %d\n", s.min, s.max, s.median);

    return 0;
}

static int compare_ints(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

struct Stats stats(int nums[MAX_NUMS], size_t length)
{
    if (length < 1)
    {
        fprintf(stderr, "File contains no integers\n");
        exit(EXIT_FAILURE);
    }

    qsort(nums, length, sizeof(int), compare_ints);

    int min, max, median;
    min = max = median = nums[0];

    for (size_t i = 1; i < length; i++)
    {
        int num = nums[i];

        if (num < min)
        {
            min = num;
        }
        else if (num > max)
        {
            max = num;
        }
    }

    size_t middle = length / 2;
    if (length % 2 == 0)
    {
        median = (nums[middle] + nums[middle - 1]) / 2;
    }
    else
    {
        median = nums[middle];
    }

    return (struct Stats){.min = min, .max = max, .median = median};
}
