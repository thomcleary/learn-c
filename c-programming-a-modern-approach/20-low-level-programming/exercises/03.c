/*
Explain what effect the following macro has on its arguments.
You may assume that the arguments have the same type
*/

#include <stdio.h>

#define M(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

int main(void)
{
    int i = 7, j = 3;
    printf("M(%d, %d): [%d]\n", i, j, M(i, j));
    // x = 0111 ^ 0011 = 0100 = 4
    // y = 0011 ^ 0100 = 0111 = 7
    // x = 0100 ^ 0111 = 0011 = 3

    // The macro swaps the values of x and y

    return 0;
}