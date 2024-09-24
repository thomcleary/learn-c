/*
Modify 08/16.c so that it includes the following function

bool are_anagrams(const char *word, const char *word2);

The function returns true if the strings pointed to by word1 and word2 are anagrams
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD_LEN 64

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char word1[MAX_WORD_LEN + 1], word2[MAX_WORD_LEN + 1];

    printf("Enter first word: ");
    scanf("%64s", word1);

    printf("Enter second word: ");
    scanf("%64s", word2);

    printf("[%s] and [%s] ", word1, word2);
    printf(are_anagrams(word1, word2) ? "are anagrams\n" : "are not anagrams\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int char_counts[26] = {0};

    while (*word1)
    {
        if (isalpha(*word1))
        {
            char_counts[tolower(*word1) - 'a']++;
        }
        word1++;
    }

    while (*word2)
    {
        if (isalpha(*word2))
        {
            char_counts[tolower(*word2) - 'a']--;
        }
        word2++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (char_counts[i] != 0)
        {
            return false;
        }
    }

    return true;
}
