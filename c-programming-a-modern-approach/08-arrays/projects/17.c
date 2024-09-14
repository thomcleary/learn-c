/*
Write a program that prints an nxn magic square
(a square arrangement of the numbers 1, 2, ..., n^2 in which the sums of rows, columns, and diagonals are all the same)
The user will specify the value of n
*/

#include <stdio.h>

#define ROW_SIZE (int)(sizeof(magic_square) / sizeof(magic_square[0]))
#define COL_SIZE (int)(sizeof(magic_square[0]) / sizeof(magic_square[0][0]))

int main(void)
{
    int size;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    printf("Enter size of magic square: ");
    scanf("%d", &size);

    if (size < 1 || size % 2 == 0)
    {
        printf("Size must be an odd number between 1 and 99.\n");
        return 0;
    }

    int magic_square[size][size];

    for (int row = 0; row < ROW_SIZE; row++)
    {
        for (int col = 0; col < COL_SIZE; col++)
        {
            magic_square[row][col] = 0;
        }
    }

    int row = 0;
    int col = size / 2;
    int n = 1;
    int n_max = size * size;

    magic_square[row][col] = n++;

    while (n <= n_max)
    {
        int next_row = row - 1;
        if (next_row < 0)
        {
            next_row = size - 1;
        }

        int next_col = (col + 1) % size;

        int next_element = magic_square[next_row][next_col];

        if (next_element == 0)
        {
            row = next_row;
            col = next_col;
            magic_square[row][col] = n;
        }
        else
        {
            row = (row + 1) % size;
            magic_square[row][col] = n;
        }

        n++;
    }

    printf("\n");
    for (int row = 0; row < ROW_SIZE; row++)
    {
        for (int col = 0; col < COL_SIZE; col++)
        {
            printf(n_max < 100 ? "%3d" : n_max < 1000 ? "%4d"
                                                      : "%5d",
                   magic_square[row][col]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}