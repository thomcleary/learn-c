/*
Modify 07.c so that it prompts for five quiz grades for each of five students
Then computes the total score and average for each student
And the average score, high score and low score for each quiz
*/

#include <stdio.h>

#define NUM_ROWS (int)(sizeof(matrix) / sizeof(matrix[0]))
#define NUM_COLUMNS (int)(sizeof(matrix[0]) / sizeof(matrix[0][0]))

int main(void)
{
    int matrix[5][5] = {0};

    for (int i = 0; i < NUM_ROWS; i++)
    {
        printf("Enter student %d's %d quiz scores: ", i + 1, NUM_COLUMNS);

        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            scanf(" %d", &matrix[i][j]);
        }
    }
    printf("\n");

    printf("Student Statistics\n\n");
    for (int i = 0; i < NUM_ROWS; i++)
    {
        printf("Student %d\n", i + 1);
        int sum = 0;
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            sum += matrix[i][j];
        }
        printf("Total score: %d\nAverage Score: %f\n\n", sum, sum / (double)NUM_COLUMNS);
    }

    printf("Quiz Statistics\n\n");
    for (int i = 0; i < NUM_COLUMNS; i++)
    {
        int low, high, sum = 0;
        low = high = matrix[0][i];

        for (int j = 0; j < NUM_ROWS; j++)
        {
            int score = matrix[j][i];
            if (score < low)
            {
                low = score;
            }
            if (score > high)
            {
                high = score;
            }

            sum += score;
        }

        printf("Quiz %d\n", i + 1);
        printf("Average score: %f\nLow score: %d\nHigh score: %d\n\n", sum / (double)NUM_ROWS, low, high);
    }

    return 0;
}