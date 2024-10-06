/*
Describe a simple way to toggle a bit.
Illustrate the technique by writing a statement that toggles bit 4 of the variable i
*/

#include <stdio.h>

unsigned short toggle_bit(unsigned short n, unsigned short bit)
{
    return n ^ (1 << (bit - 1));
}

int main(void)
{
    unsigned short i = ~0;

    printf("i: [%d]\n", toggle_bit(i, 0));
    printf("Toggle bit 1: [%d]\n", toggle_bit(i, 1));
    printf("Toggle bit 3: [%d]\n", toggle_bit(i, 3));
    printf("Toggle bit 8: [%d]\n", toggle_bit(i, 8));

    return 0;
}