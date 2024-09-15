/*
Modify 08/17.c so that it includes the following functions

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);
*/

#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
    int size;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    printf("Enter size of magic square: ");
    scanf("%d", &size);

    if (size < 1 || size > 99 || size % 2 == 0)
    {
        printf("Size must be an odd number between 1 and 99.\n");
        return 0;
    }

    int magic_square[size][size];

    create_magic_square(size, magic_square);
    print_magic_square(size, magic_square);

    return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            magic_square[row][col] = 0;
        }
    }

    int row = 0;
    int col = n / 2;
    int square = 1;
    int square_max = n * n;

    magic_square[row][col] = square++;

    while (square <= square_max)
    {
        int next_row = row - 1;
        if (next_row < 0)
        {
            next_row = n - 1;
        }

        int next_col = (col + 1) % n;

        int next_element = magic_square[next_row][next_col];

        if (next_element == 0)
        {
            row = next_row;
            col = next_col;
            magic_square[row][col] = square;
        }
        else
        {
            row = (row + 1) % n;
            magic_square[row][col] = square;
        }

        square++;
    }
}

void print_magic_square(int n, int magic_square[n][n])
{
    printf("\n");
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%5d", magic_square[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}
