/*
(a) Write a program that reads a message, then prints the reversal of the message

Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD

(b) Revise the program to use a pointer instead of an integer to keep track of the current position in the array
*/

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