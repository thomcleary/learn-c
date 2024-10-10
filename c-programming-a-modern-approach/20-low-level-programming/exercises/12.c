#include <stdio.h>
#include <assert.h>

/*
The following function supposedly combines two bytes to form an unsigned short integer.
Explain why the function doesn't work and show how to fix it
*/

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    // '+' has a higher precedence than '<<'
    // Causing the return value to be the high_byte right bit shidted by '8 + low_byte' places
    return high_byte << 8 + low_byte;
}

unsigned short create_short_fixed(unsigned char high_byte, unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}

int main(void)
{
    unsigned char high = 200, low = 7;
    // 1100_1000__0000_0111
    // 51207

    printf("create_short(%d, %d): %u\n", high, low, create_short(high, low));

    printf("create_short_fixed(%d, %d): %u\n", high, low, create_short_fixed(high, low));
    assert(create_short_fixed(high, low) == 51207);

    return 0;
}