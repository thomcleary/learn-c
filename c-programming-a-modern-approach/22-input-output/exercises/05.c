/*
Is there any difference between the printf conversion specifiers
- %.4d
- %04d

If so, explain what it is
*/

#include <stdio.h>

int main(void)
{
    int num = 456;

    // %.4d
    // precision: .4 (for 'd' conversion specifier = minimum number of digits)
    // conversion specifier: d
    // num => 0456
    printf("%%.4d: %.4d\n", num);

    // %04d
    // flags: 0 (pad with leading zeros up to field width)
    // minimum field width: 4 (If an item is too small to occupy this number, it will be padded)
    // conversion specifier: d
    // num => 0456
    printf("%%04d: %04d\n", num);

    return 0;
}