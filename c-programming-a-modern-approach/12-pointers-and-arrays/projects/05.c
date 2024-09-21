/*
Modify 08/14.c so that it uses a pointer instead of an integer to keep track of the current position in the array that contains the sentence
*/

#include <stdio.h>

#define N 128

int main(void)
{
    char sentence[N];
    char *ch = sentence;
    char sentence_terminator = '\0';

    printf("Enter a sentence: ");

    while (ch < sentence + N)
    {
        char next = getchar();

        if (next == '\n')
        {
            break;
        }

        if (next == '.' || next == '?' || next == '!')
        {
            sentence_terminator = next;
            break;
        }

        *ch = next;
        ch++;
    }

    char *word_end = --ch;

    printf("Reversal of sentence:");

    while (word_end >= sentence)
    {
        while (word_end >= sentence && *word_end == ' ')
        {
            word_end--;
        }

        char *word_start = word_end;

        while (word_start >= sentence && *word_start != ' ')
        {
            word_start--;
        }

        printf(" ");
        for (char *ch = word_start + 1; ch <= word_end; ch++)
        {
            printf("%c", *ch);
        }

        word_end = word_start;
    }

    if (sentence_terminator != '0')
    {
        putchar(sentence_terminator);
    }

    putchar('\n');

    return 0;
}