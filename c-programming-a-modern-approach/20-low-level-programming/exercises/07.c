/*
Write the following functions:

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

rotate_left should return the result of shifting the bits in i to the left by n places,
with the bits that were "shifted off" moved to the right end of i.
(For example, the call rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32 bits long.)

rotate_right is similar, but it should "rotate" buts to the right instead of the left.
*/

#include <stdio.h>
#include <assert.h>

#define NUM_BITS(x) (sizeof((x)) * 8)

unsigned int rotate_left(unsigned int i, int n)
{
    size_t num_bits = NUM_BITS(i);
    n %= num_bits;

    return (i << n) | (i >> (num_bits - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    size_t num_bits = NUM_BITS(i);
    n %= num_bits;

    return (i >> n) | (i << (num_bits - n));
}

int main(void)
{
    unsigned int i = 0x12345678;

    printf("i: %#x\n", i);
    printf("NUM_BITS(i): %lu\n\n", NUM_BITS(i));

    printf("rotate_left(i, 0): %#x\n", rotate_left(i, 0));
    printf("rotate_right(i, 0): %#x\n\n", rotate_right(i, 0));

    assert(rotate_left(i, 0) == i);
    assert(rotate_right(i, 0) == i);

    printf("rotate_left(i, 32): %#x\n", rotate_left(i, 32));
    printf("rotate_right(i, 32): %#x\n\n", rotate_right(i, 32));

    assert(rotate_left(i, 32) == i);
    assert(rotate_right(i, 32) == i);

    printf("rotate_left(i, 4): %#x\n", rotate_left(i, 4));
    printf("rotate_right(i, 4): %#x\n\n", rotate_right(i, 4));

    assert(rotate_left(i, 4) == 0x23456781);
    assert(rotate_right(i, 4) == 0x81234567);

    printf("rotate_left(i, 12): %#x\n", rotate_left(i, 12));
    printf("rotate_right(i, 12): %#x\n\n", rotate_right(i, 12));

    assert(rotate_left(i, 12) == 0x45678123);
    assert(rotate_right(i, 12) == 0x67812345);

    printf("rotate_left(i, 36): %#x\n", rotate_left(i, 36));
    printf("rotate_right(i, 36): %#x\n\n", rotate_right(i, 36));

    assert(rotate_left(i, 36) == rotate_left(i, 4));
    assert(rotate_right(i, 36) == rotate_right(i, 4));

    return 0;
}