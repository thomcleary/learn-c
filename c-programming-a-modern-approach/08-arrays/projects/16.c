/*
Write a program that tests whether two words are anagrams
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int char_counts[26] = {0};
    char ch;

    printf("Enter first word: ");
    while ((ch = tolower(getchar())) != '\n')
    {
        if (!isalpha(ch))
        {
            continue;
        }

        char_counts[ch - 'a']++;
    }

    printf("Enter second word: ");
    while ((ch = tolower(getchar())) != '\n')
    {
        if (!isalpha(ch))
        {
            continue;
        }

        char_counts[ch - 'a']--;
    }

    bool is_anagram = true;
    for (int i = 0; i < (int)(sizeof(char_counts) / sizeof(char_counts[0])); i++)
    {
        is_anagram = char_counts[i] == 0;

        if (!is_anagram)
        {
            break;
        }
    }

    printf(is_anagram ? "The words are anagrams\n" : "The words are not anagrams\n");

    return 0;
}