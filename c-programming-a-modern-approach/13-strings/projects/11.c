/*
Modify 07/13.c so that it includes the following function:

double compute_average_word_length(const char *sentence);

The function returns the average length of the words in the string pointed to by sentence
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SENTENCE_MAX_LEN 80

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[SENTENCE_MAX_LEN];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int ln = strlen(sentence);
    if (sentence[ln - 1] == '\n')
    {
        sentence[ln - 1] = '\0';
    }

    printf("Average word length: %f\n", compute_average_word_length(sentence));

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int word_count = 1;
    int letter_count = 0;

    // skip initial space
    while (*sentence && !isalpha(*sentence))
    {
        sentence++;
    }

    while (*sentence)
    {
        // letter
        if (isalpha(*sentence))
        {
            letter_count++;
            sentence++;
            continue;
        }

        // punctuation
        if (!isspace(*sentence))
        {
            sentence++;
            continue;
        }

        // space between words
        while (*sentence && !isalpha(*sentence))
        {
            sentence++;
        }

        if (*sentence)
        {
            word_count++;
        }
    }

    return letter_count / ((double)word_count);
}
