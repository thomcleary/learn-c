/*
Let TOUPPER be the following macro:

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

Let s be a string and let i be an int variable.
Show the output produced by each of the following program fragments

(a)
strcpy(s, "abcd");
i = 0;
putchar(TOUPPER(s[++i]));

(b)
strcpy(s, "0123");
i = 0;
putchar(TOUPPER(s[++i]));
*/

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void)
{
    char s[8];
    int i;

    strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

    return 0;
}