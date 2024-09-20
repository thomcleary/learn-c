/*
Section 8.2 had a program fragment in which two nested for loops initialized the array ident
for use as an identity matrix.
Rewrite thise code, using a single pointer to step through the array one element at a time
Hint: since we won't be using row and col index variables, it won't be easy to tell where to store 1.
Instead, we can use the fact that the first element of the array should be 1,
the next N elements should be 0, the next element should be 1 and so forth.
Use a variable to keep track of how many consecutive 0s have been stored; when the count reaches N, it's time to store 1
*/

#include <stdio.h>

#define N 10

int main(void)
{
    double ident[N][N];

    int zeros = 0;
    for (double *p = &ident[0][0]; p <= &ident[N - 1][N - 1]; p++)
    {
        if (zeros == 0)
        {
            *p = 1.0;
            zeros++;
        }
        else
        {
            *p = 0.0;
            zeros = (zeros + 1) % (N + 1);
        }
    }

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%f ", ident[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}