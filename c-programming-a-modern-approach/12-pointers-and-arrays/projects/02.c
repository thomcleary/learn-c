/*
(a) Write a program that reads a message, then checks whether it's a palindrome
Ignore all the characters that aren't letters.
Use integer variables to keep track of positions in the array.

(b) Revise the program to use pointers instead of integers to keep track of positions in the array
*/

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