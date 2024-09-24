/*
Modify 07/10.c so that it includes the following function:

int compute_vowel_count(const char *sentence);

The function returns the number of vowels in the string pointed to by the sentence parameter
*/

int compute_vowel_count(const char *sentence);

#include <ctype.h>
#include <stdio.h>

#define SENTENCE_MAX_LEN 80

int main(void)
{
    char ch, sentence[SENTENCE_MAX_LEN + 1];

    printf("Enter a sentence: ");

    int i = 0;
    while (i <= SENTENCE_MAX_LEN && (ch = toupper(getchar())) != '\n')
    {
        sentence[i] = ch;
        i++;
    }

    sentence[i + 1] = '\0';

    printf("Your sentence contains %d vowels\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int vowels = 0;

    while (*sentence)
    {
        char ch = *sentence;

        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }

        sentence++;
    }

    return vowels;
}
