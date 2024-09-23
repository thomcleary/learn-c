/*
Modify 07/05.c so that it includes the following function:

int compute_scrabble_value(const char *word);

The function returns the SCRABBLE value of the string pointed to by word
*/

char *read_word(char *word, int length);
int compute_scrabble_value(const char *word);

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 7

int main(void)
{
    char word[MAX_WORD_LEN + 1];

    read_word(word, MAX_WORD_LEN + 1);

    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;
}

char *read_word(char *word, int length)
{
    printf("Enter a word: ");

    int i = 0;
    for (; i < length - 1; i++)
    {
        char ch = getchar();

        if (ch == '\n')
        {
            break;
        }

        *(word + i) = toupper(ch);
    }

    *(word + i) = '\0';

    return word;
}

int compute_scrabble_value(const char *word)
{
    int value = 0;

    while (*word)
    {
        switch (*word)
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
            printf("'%c' is not valid scrabble letter.\n", *word);
            return 0;
        }

        word++;
    }

    return value;
}
