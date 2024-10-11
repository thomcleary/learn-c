/*
Starting with the 386 processor, x86 CPUs have 32-bit registers named
EAX, EBX, ECX, and EDX.

The second half (the least significant bits) of these registers, is the same as
AX, BX, CX and DX, respectively.

Modify the regs union so that it includes these registers as well as the older ones.
Your union should be set up so that modifying EAX changes AX and modifying AX changes the second half of EAX.
(The other new registers will work in a similar fashion).

You'll need to add some "dummy" members to the word and byte structures,
corresponding to the other half of EAX, EBX, ECX, and EDX.

Declare the type of the new registers to be DWORD (double word),
which should be defined as unsigned long.

Don't forget that the x86 architecture is little-endian
*/

#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD; // long is 64 bit on my machine

union registers
{
    struct
    {
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct
    {
        WORD ax, a_, bx, b_, cx, c_, dx, d_;
    } word;
    struct
    {
        BYTE al, ah, a_, a__, bl, bh, b_, b__, cl, ch, c_, c__, dl, dh, d_, d__;
    } byte;
};

int main(void)
{
    union registers regs;

    regs.byte.ch = 0x12;
    regs.byte.cl = 0x34;
    printf("ch = 0x12\n");
    printf("cl = 0x34\n");
    printf("CH: %#hx\n", regs.byte.ch);
    printf("CL: %#hx\n", regs.byte.cl);
    printf("CX: %#hx\n", regs.word.cx);
    printf("ECX: %#x\n\n", regs.dword.ecx);

    regs.dword.ecx = 0x56784321;
    printf("ECX = 0x56784321\n");
    printf("ECX: %#x\n", regs.dword.ecx);
    printf("CX: %#hx\n", regs.word.cx);
    printf("CH: %#hx\n", regs.byte.ch);
    printf("CL: %#hx\n", regs.byte.cl);

    return 0;
}
