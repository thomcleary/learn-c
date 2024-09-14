/*
Write a program that reads a 5 x 5 array of integers and then prints the row sums and the column sums
*/

#include <stdio.h>

#define NUM_ROWS (int)(sizeof(matrix) / sizeof(matrix[0]))
#define NUM_COLUMNS (int)(sizeof(matrix[0]) / sizeof(matrix[0][0]))

int main(void)
{
    int matrix[5][5] = {0};

    for (int i = 0; i < NUM_ROWS; i++)
    {
        printf("Enter row %d: ", i + 1);

        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            scanf(" %d", &matrix[i][j]);
        }
    }
    printf("\n");

    printf("Row totals: ");
    for (int i = 0; i < NUM_ROWS; i++)
    {
        int sum = 0;
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            sum += matrix[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n");

    printf("Column totals: ");
    for (int i = 0; i < NUM_COLUMNS; i++)
    {
        int sum = 0;
        for (int j = 0; j < NUM_ROWS; j++)
        {
            sum += matrix[j][i];
        }
        printf("%d ", sum);
    }
    printf("\n");

    return 0;
}