/*
Write a program that computes the value of a scrabble word by summing the value of its letters
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int value = 0;

    printf("Enter a word: ");

    while ((ch = toupper(getchar())) != '\n')
    {
        switch (ch)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
            value += 1;
            break;
        case 'D':
        case 'G':
            value += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            value += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            value += 4;
            break;
        case 'K':
            value += 5;
            break;
        case 'J':
        case 'X':
            value += 8;
            break;
        case 'Q':
        case 'Z':
            value += 10;
            break;
        default:
            printf("'%c' is not valid scrabble letter.\n", ch);
            return 0;
        }
    }

    printf("Scrabble value: %d\n", value);

    return 0;
}
