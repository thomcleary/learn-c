/*
(a) Use the bitwise operators to write the following function:

unsigned short swap_bytes(unsigned short i);

swap_bytes should return the number that results from swapping the two bytes in i.
(Short integers occupy two bytes on most computers).
For example, if i has the value 0x1234 (00010010_00110100 in binary),
then swap_bytes should return 0x3412 (00110100_00010010 in binary).

Test your function by writing a program that reads a number in hexadecimal,
then writes the number with its bytes swapped:

Enter a hexadecimal number (up to four digits): 1234
Number with bytes swapped: 3412

Hint: use %hx conversion to read and write hex numbers.

(b) Condense the swap_bytes function so that its body is a single statement
*/

#include <stdio.h>

#define EIGHT_BITS 255

unsigned short swap_bytes(unsigned short i)
{
    return (i << 8) | (i >> 8);

    // (a)
    // unsigned short high = i >> 8;
    // i <<= 8;
    // return i | high;
}

int main(void)
{
    unsigned short n;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf(" %hx", &n);
    printf("Number with swapped bytes: %hx\n", swap_bytes(n));

    return 0;
}
