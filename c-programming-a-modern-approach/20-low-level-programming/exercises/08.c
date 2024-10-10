#include <assert.h>

/*
Let f be the following function
*/

unsigned int f(unsigned int i, int m, int n)
{
    return (i >> (m + 1 - n)) & ~(~0 << n);
}

/*
(a) What is the value of ~(~0 << n)?
(b) What does this function do?
*/

int f_a(int n)
{
    return ~(~0 << n);
}

#include <stdio.h>

int main(void)
{
    unsigned int i = 1000;
    int m = 5;
    int n = 3;

    // (a): ~(~0 << n) === (2^(n)) - 1
    // n = 3
    // 0          = 00000000_00000000_00000000_00000000
    // ~0         = 11111111_11111111_11111111_11111111
    // ~0 << 3    = 11111111_11111111_11111111_11111000
    // ~(~0 << 3) = 00000000_00000000_00000000_00000111 = 7 = (2^3) - 1
    printf("~(~0 << n), x=%d: %d\n", n, f_a(n));
    assert(f_a(n) == 7);

    // (b)
    // i = 1000 = 00000000_00000000_00000011_11101000
    // m = 5
    // n = 3

    // RHS produces an int with value (2^n)-1, so n bits set to 1
    // 00000000_00000000_00000000_00000111
    //
    // LHS = (i >> (m + 1 - n))
    // 00000000_00000000_00000011_11101000 >> (5 + 1 - 3)
    // 00000000_00000000_00000011_11101000 >> (3)
    // 00000000_00000000_00000000_01111101
    //
    // LHS & RHS
    // 00000000_00000000_00000000_01111101 & 00000000_00000000_00000000_00000111
    // 00000000_00000000_00000000_00000101

    // It extracts a bit field from i
    // With n being the length of the bit field
    // And m being the position of the most significant digit of the bit field (indexing starting at 0)

    printf("f(%d, %d, %d): %d\n", i, m, n, f(i, m, n));
    assert(f(i, m, n) == 5);

    return 0;
}