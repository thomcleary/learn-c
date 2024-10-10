/*
Write the following function:

unsigned int reverse_bits(unsigned int n);

reverse_bits should return an unsigned integer whose bits are the same as those in n but in reverse order
*/

#include <stdio.h>
#include <assert.h>

unsigned int reverse_bits(unsigned int n)
{
    unsigned int reversed = 0;
    int curr_bit = 1;
    int shift = (sizeof(reversed) * 8) - 1;

    while (shift >= 0)
    {
        if (n & curr_bit)
        {
            reversed |= (unsigned int)(1 << shift);
        }

        curr_bit *= 2;
        shift--;
    }

    return reversed;
}

int main(void)
{
    unsigned int n = 99;

    // n = 00000000_00000000_00000000_01100011
    // n_reversed = 11000110_00000000_00000000_00000000 = 3321888768
    printf("reverse_bits(%#x): %#x\n", n, reverse_bits(n));
    assert(reverse_bits(n) == 3321888768);

    n = 1;
    printf("reverse_bits(%#x): %#x\n", n, reverse_bits(n));
    assert(reverse_bits(n) == 2147483648);

    n = 15;
    printf("reverse_bits(%#x): %#x\n", n, reverse_bits(n));
    assert(reverse_bits(n) == 4026531840);

    return 0;
}