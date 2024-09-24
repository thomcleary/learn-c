/*
Modify 12/01.c so that it includes the following function

void reverse(char *message);

The function reverses the string pointed to by message.
*/

#include <stdio.h>

#define N 128

void reverse(char *message);

int main(void)
{
    char message[N + 1];
    char *ch = message;

    printf("Enter a message: ");

    while (ch < message + N)
    {
        char next = getchar();

        if (next == '\n')
        {
            break;
        }

        *ch++ = next;
    }
    *ch = '\0';

    reverse(message);

    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *message)
{
    char *left = message;
    char *right = left;

    while (*right)
    {
        right++;
    }
    right--;

    while (left < right)
    {
        char left_ch = *left;
        *left = *right;
        *right = left_ch;

        left++;
        right--;
    }
}
