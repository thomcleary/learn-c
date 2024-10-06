/*
In computer graphics, colors are often stored as three numbers, representing red, green and blue intensities.
Suppose that each number requires eight bits, and we'd like to store all three values in a single long integer.
Write a macro named MK_COLOR with three parameters (the red, green and blue intensities).
MK_COLOR should return a long in which the last three bytes contain the red, green and blue intensities,
with the red value as the last byte and the green value as the next-to-last byte.
*/

#include <stdio.h>
#include <assert.h>

#define MK_COLOR(r, g, b) (unsigned long)(b << 16 | g << 8 | r)

unsigned long make_color(unsigned short red, unsigned short green, unsigned short blue)
{
    return (long)(blue << 16 | green << 8 | red);
}

int main(void)
{
    unsigned short red = 64;   // 0100_0000
    unsigned short green = 16; // 0001_0000
    unsigned short blue = 7;   // 0000_0111
    // color = 0000_0111__0001_0000__0100_0000 = 462912

    assert(MK_COLOR(red, green, blue) == 462912);

    printf("make_color(%d, %d, %d): %ld\n", red, green, blue, make_color(red, green, blue));
    printf("MK_COLOR(%d, %d, %d): %ld\n", red, green, blue, MK_COLOR(red, green, blue));

    return 0;
}