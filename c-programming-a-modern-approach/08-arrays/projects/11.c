/*
Modify 07/04.c so that the program labels its output
You may assume that the phone number is no more than 15 characters long
*/

#include <stdio.h>
#include <ctype.h>

#define PHONE_NUMBER_MAX_LENGTH 15

int main(void)
{
    char phone_number[PHONE_NUMBER_MAX_LENGTH];

    printf("Enter a phone number: ");

    int phone_number_length = 0;
    char ch;
    while ((ch = toupper(getchar())) != '\n' && phone_number_length < PHONE_NUMBER_MAX_LENGTH)
    {
        phone_number[phone_number_length++] = ch;
    }

    printf("In numeric form: ");
    for (int i = 0; i < phone_number_length; i++)
    {
        char ch = phone_number[i];

        switch (ch)
        {
        case 'A':
        case 'B':
        case 'C':
            putchar('2');
            break;
        case 'D':
        case 'E':
        case 'F':
            putchar('3');
            break;
        case 'G':
        case 'H':
        case 'I':
            putchar('4');
            break;
        case 'J':
        case 'K':
        case 'L':
            putchar('5');
            break;
        case 'M':
        case 'N':
        case 'O':
            putchar('6');
            break;
        case 'P':
        case 'R':
        case 'S':
            putchar('7');
            break;
        case 'T':
        case 'U':
        case 'V':
            putchar('8');
            break;
        case 'W':
        case 'X':
        case 'Y':
            putchar('9');
            break;
        default:
            putchar(ch);
        }
    }

    printf("\n");

    return 0;
}