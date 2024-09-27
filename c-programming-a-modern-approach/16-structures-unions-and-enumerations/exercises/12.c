/*
Suppose the u is the following union
*/

union
{
    double a;
    struct
    {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} u;

/*
If char values occupy 1 byte, int values occupy 4 bytes, and double values occupy 8 bytes,
how much space will a C compiler allocate for u?

(assume the compiler leaves no "holes" betwee members)
*/

#include <stdio.h>

int main(void)
{
    // a = 8 bytes
    // e = 16 bytes
    // - e.b = 4 bytes
    // - e.c = 8 bytes
    // - e.d = 4 bytes
    // f = 4 bytes

    printf("sizeof(u) assumption: %d bytes\n", 16);
    printf("sizeof(u) actual: %ld bytes\n", sizeof u);

    return 0;
}