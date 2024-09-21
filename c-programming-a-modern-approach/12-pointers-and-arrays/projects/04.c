/*
Simplify 02.c by taking advantage of the fact that an array name can be used as a pointer
*/

// NOTE: Already done in 02.c

#include <ctype.h>
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

        if (isalpha(next))
        {
            *ch = toupper(next);
            ch++;
        }
    }

    char *left = message;
    char *right = ch;

    while (left < right)
    {
        if (*left != *right)
        {
            printf("Not a palindrome\n");
            return 0;
        }

        left++;
        right--;
    }

    printf("Palindrome\n");

    return 0;
}