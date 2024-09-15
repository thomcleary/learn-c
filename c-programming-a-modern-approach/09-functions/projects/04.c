/*
Modify 08/16.c so that it includes the following functions

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int char_counts1[26] = {0};
    int char_counts2[26] = {0};

    printf("Enter first word: ");
    read_word(char_counts1);

    printf("Enter second word: ");
    read_word(char_counts2);

    bool is_anagram = equal_array(char_counts1, char_counts2);

    printf(is_anagram ? "The words are anagrams\n" : "The words are not anagrams\n");

    return 0;
}

void read_word(int counts[26])
{
    char ch;

    while ((ch = tolower(getchar())) != '\n')
    {
        if (!isalpha(ch))
        {
            continue;
        }

        counts[ch - 'a']++;
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (counts1[i] != counts2[i])
        {
            return false;
        }
    }

    return true;
}
