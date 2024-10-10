/*
When stored according to the IEEE floating-point standard,
a float value consists of a 1-bit signed (most signifcant bit),
and 8-bit exponent, and a 23-bit fraction, in that order.
Design a structure type that occupies 32 bits,
with bit-field members corresponding to the sign, exponent and fraction.
Declare the bit-fields to ahve type `unsigned int`.
Check the manual for your compiler to determine the order of the bit fields.
*/

#include <stdio.h>
#include <assert.h>

struct IEEE_float
{
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
};

int main(void)
{
    struct IEEE_float n = {.sign = 1, .exponent = 0, .fraction = 0};

    unsigned int test = *((unsigned int *)&n);

    printf("n: %u\n", test);
    assert(test == 2147483648); // Proves ordering of bitfields (sign is most significant bit)
}