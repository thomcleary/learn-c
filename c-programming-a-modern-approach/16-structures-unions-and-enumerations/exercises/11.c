/*
Suppose that s is the following structure
*/

struct
{
    double a;
    union
    {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} s;

/*
If char values occupy one byte, int values occupy four bytes and double values occupy eight bytes,
how much space will a C compiler allocate for s?

Assume that the compiler leaves no "holes" between members.
*/

#include <stdio.h>

int main(void)
{
    // a = 8 bytes
    // e = 8 bytes
    // f = 4 bytes
    printf("sizeof(s) assumption: %d bytes\n", 8 + 8 + 4);
    printf("sizeof(s) actual: %ld bytes\n", sizeof s);

    return 0;
}