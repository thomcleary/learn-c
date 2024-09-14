/*
Write a program that reverses the words in a sentence
*/

#include <stdio.h>

int main(void)
{
    char sentence[1024];
    char sentence_terminator = '0';

    printf("Enter a sentence: ");

    int num_chars = 0;
    for (; num_chars < (int)(sizeof(sentence) / sizeof(sentence[0])); num_chars++)
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

        sentence[num_chars] = next;
    }

    int word_end = num_chars - 1;
    int word_start = word_end;

    printf("Reversal of sentence:");

    while (word_end >= 0)
    {
        while (word_end >= -1 && sentence[word_end] == ' ')
        {
            word_end--;
            word_start--;
        }

        if (word_end == -1)
        {
            break;
        }

        while (word_start >= 0 && sentence[word_start] != ' ')
        {
            word_start--;
        }

        putchar(' ');
        for (int i = word_start + 1; i <= word_end; i++)
        {
            putchar(sentence[i]);
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