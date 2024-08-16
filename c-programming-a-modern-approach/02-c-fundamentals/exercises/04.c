/* Prints values of some unintialised variables */

#include <stdio.h>

int main(void)
{
    int a, b, c;
    float d, e, f;

    printf("a: [%d]\n", a);
    printf("b: [%d]\n", b);
    printf("c: [%d]\n", c);
    printf("d: [%f]\n", d);
    printf("e: [%f]\n", e);
    printf("f: [%f]\n", f);

    return 0;
}