/*
(a) Assume that the variable s has been  declared as follows

struct {
    int flag: 1;
} s;

With some compilers, executing the following statement causes 1 to be displayed,
but with other compilers, the output is -1. Explain the reason for this behaviour.

s.flag = 1;
printf("%d\n", s.flag);

(b) How can this problem be avoided
*/

#include <stdio.h>
#include <assert.h>

struct flag
{
    int flag : 1;
};

struct unsigned_flag
{
    unsigned int flag : 1;
};

struct signed_flag
{
    signed int flag : 1;
};

int main(void)
{
    // (a)
    // When using a bitfield if you do not specify signed/unsigned for an int
    // it is implementation defined on which it will be
    // A single bit has 2 possible values 0 or 1
    // In the unsigned case this can represent 0 or 1
    // In the signed case, this can represent:
    //   - 0 when the sign bit
    //   - -1 when the sign bit is 1

    // (b)
    // This can be avoided by explicitly declaring the type as either signed or unsigned
    // depending on what the behaviour should be

    struct flag f = {.flag = 1};
    struct unsigned_flag uf = {.flag = 1};
    struct signed_flag sf = {.flag = 1};

    printf("flag: %d\n", f.flag);
    printf("unsigned_flag: %d\n", uf.flag);
    printf("signed_flag: %d\n", sf.flag);

    return 0;
}
