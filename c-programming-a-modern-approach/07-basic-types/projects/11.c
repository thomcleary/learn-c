/*
Write a program that takes a first name and a last name entered by the user
and displays the last name, a comma, and the first initial, followed by a period
*/

#include <stdio.h>

int main(void)
{
    char ch;

    printf("Enter a first and last name: ");

    // Trim start
    while ((ch = getchar()) == ' ')
    {
        ;
    }

    char initial = ch;

    // Trim rest of first name
    while ((ch = getchar()) != ' ')
    {
        ;
    }

    // Trim to last name
    while ((ch = getchar()) == ' ')
    {
        ;
    }

    do
    {
        putchar(ch);
    } while ((ch = getchar()) != ' ' && ch != '\n');

    putchar(',');
    putchar(' ');
    putchar(initial);
    putchar('.');
    putchar('\n');

    return 0;
}