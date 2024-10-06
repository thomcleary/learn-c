/*
Sow the output produced by each of the following program fragments.
Assume that i, j, and k are unsigned short variables.
*/

#include <stdio.h>

int main(void)
{
    unsigned short i, j, k;

    // (a)
    i = 8, j = 9;
    printf("(a) %d\n", i >> 1 + j >> 1);
    // i = 0000_1000
    // j = 0000_1001
    // j + 1 = 0000_1010 = 10
    // i >> 10 = 0000_0000 = 0
    // 0 >> 1 = 0000_0000 = 0

    // (b)
    i = 1;
    printf("(b) %d\n", i & ~i);
    // i = 0000_0001
    // ~i = 1111_1110
    // i & ~i = 0000_0000 = 0

    // (c)
    i = 2, j = 1, k = 0;
    printf("(c) %d\n", ~i & j ^ k);
    // i = 0000_0010
    // j = 0000_0001
    // k = 0000_0000
    // ~i = 1111_1101
    // ~i & j = 0000_0001
    // (~i & j) ^ k = 0000_0001 = 1

    // (d)
    i = 7;
    j = 8;
    k = 9;
    printf("(d) %d\n", i ^ j & k);
    // j & k = 0000_1000 & 0000_1001 = 0000_1000
    // i ^ 8 = 0000_0111 & 0000_1000 = 0000_1111 = 15

    return 0;
}