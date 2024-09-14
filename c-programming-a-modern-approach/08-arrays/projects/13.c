/*
Modify 07/11.c so that the program labels its output
The program will need to store the last name, but no the first name in an array of characters
You may assume that the last name is no more than 20 characters long
*/

#include <stdio.h>

int main(void)
{
    char initial;

    printf("Enter a first and last name: ");

    // Trim start
    while ((initial = getchar()) == ' ')
    {
        ;
    }

    // Trim rest of first name
    while (getchar() != ' ')
    {
        ;
    }

    char last_name[20];

    // Trim to last name
    while ((last_name[0] = getchar()) == ' ')
    {
        ;
    }

    int i = 1;
    while (i < (int)(sizeof(last_name) / sizeof(last_name[0])))
    {
        char next = getchar();

        if (next == '\n')
        {
            break;
        }

        last_name[i++] = next;
    }

    printf("You entered the name: ");
    for (int j = 0; j <= i; j++)
    {
        putchar(last_name[j]);
    }

    putchar(',');
    putchar(' ');
    putchar(initial);
    putchar('.');
    putchar('\n');

    return 0;
}