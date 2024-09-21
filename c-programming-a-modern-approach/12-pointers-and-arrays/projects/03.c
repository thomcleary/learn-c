/*
Simplify 01.c by taking advantage of the fact that an array name can be used as a pointer
*/

// NOTE: Already done in 01.c

#include <stdio.h>

#define N 128

int main(void)
{
    char message[N];
    char *ch = message;

    printf("Enter a message: ");

    while (ch < message + N)
    {
        char next = getchar();

        if (next == '\n')
        {
            ch--;
            break;
        }

        *ch = next;
        ch++;
    }

    printf("Reversal is: ");

    for (; ch >= message; ch--)
    {
        printf("%c", *ch);
    }
    printf("\n");

    return 0;
}