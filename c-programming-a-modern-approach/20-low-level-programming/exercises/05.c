/*
Write macros named GET_RED, GET_GREEN, GET_BLUE that,
when given a color as an argument (see exercise 4),
return its 8-bit red, green and blue intensities
*/

#include <stdio.h>
#include <assert.h>

#define EIGHT_BITS 255

#define GET_BYTE(color, byte) ((unsigned short)(((color) >> (((byte) - 1) * 8)) & EIGHT_BITS))
#define GET_RED(color) GET_BYTE(color, 1)
#define GET_GREEN(color) GET_BYTE(color, 2)
#define GET_BLUE(color) GET_BYTE(color, 3)

unsigned short get_byte(unsigned long n, int byte)
{
    return (n >> ((byte - 1) * 8)) & EIGHT_BITS;
}

unsigned short get_red(unsigned long color)
{
    return get_byte(color, 1);
}

unsigned short get_green(unsigned long color)
{
    return get_byte(color, 2);
}

unsigned short get_blue(unsigned long color)
{
    return get_byte(color, 3);
}

int main(void)
{
    unsigned long color = 462912;       // 0000_0111__0001_0000__0100_0000
    unsigned short expected_red = 64;   // 0100_0000
    unsigned short expected_green = 16; // 0001_0000
    unsigned short expected_blue = 7;   // 0000_0111

    printf("get_red(color): %d\n", get_red(color));
    printf("GET_RED(color): %d\n\n", GET_RED(color));

    printf("get_green(color): %d\n", get_green(color));
    printf("GET_GREEN(color): %d\n\n", GET_GREEN(color));

    printf("get_blue(color): %d\n", get_blue(color));
    printf("GET_BLUE(color): %d\n\n", GET_BLUE(color));

    assert(get_red(color) == expected_red);
    assert(get_green(color) == expected_green);
    assert(get_blue(color) == expected_blue);

    assert(GET_RED(color) == expected_red);
    assert(GET_GREEN(color) == expected_green);
    assert(GET_BLUE(color) == expected_blue);

    return 0;
}