/*
Modify 12/02.c so that it includes the following function

bool is_palindrome(const char *message);

The function returns true if the string pointed to by message is a palindrome
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define N 128

bool is_palindrome(const char *message);

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

        if (isalpha(next))
        {
            *ch = toupper(next);
            ch++;
        }
    }
    *ch = '\0';

    printf(is_palindrome(message) ? "Palindrome\n" : "Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *left = message;
    const char *right = message;

    while (*right)
    {
        right++;
    }
    right--;

    while (left < right)
    {
        if (*left != *right)
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
