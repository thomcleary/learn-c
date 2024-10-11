/*
Design a union that makes it possible to view a 32-bit value as either a float or the structure described in exercise 14.
Write a program that stores 1 in the structures sign field, 128 in the exponent field and 0 in the fraction field,
then prints the float value stored in the union.
(The answer should be -2.0 if you've set up the bit-fields correctly)
*/

#include <stdio.h>

struct IEEE_float
{
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
};

union my_float
{
    float f;
    struct IEEE_float ieeef;
};

int main(void)
{
    union my_float n = {.ieeef = {.sign = 1, .exponent = 128, .fraction = 0}};

    printf("n: %.2f\n", n.f);

    return 0;
}