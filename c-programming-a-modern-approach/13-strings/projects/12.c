/*
Modify 08/14.c so that it stores the words in a 2D char array as it reads the sentence,
with each row of the array storing a single word.
Assume that the sentence contains no more than 30 words and no word is more than 20 characters long.
Be sure to store a null character at the end of each word so that it can be treated as a string.
*/

#include <ctype.h>
#include <stdio.h>

#define WORDS_MAX 30
#define WORD_MAX_LENGTH 20

int main(void)
{
    char words[WORDS_MAX][WORD_MAX_LENGTH + 1];

    char sentence_terminator = '\0';

    printf("Enter a sentence: ");

    int num_words = 0;
    int num_letters = 0;
    char ch = getchar();

    while (num_words < WORDS_MAX && !sentence_terminator && ch != '\n' && ch != EOF)
    {
        while (isalpha(ch) && num_letters < WORD_MAX_LENGTH)
        {
            words[num_words][num_letters++] = ch;
            ch = getchar();
        }

        if (num_letters > 0)
        {
            words[num_words++][num_letters] = '\0';
            num_letters = 0;
        }

        while (!isalpha(ch) && ch != EOF)
        {
            if (ch == '\n')
            {
                break;
            }

            if (ch == '.' || ch == '?' || ch == '!')
            {
                sentence_terminator = ch;
                break;
            }

            ch = getchar();
        }
    }

    printf("Reversal of sentence: ");

    for (int i = num_words - 1; i >= 0; i--)
    {
        printf("%s", words[i]);

        if (i > 0)
        {
            printf(" ");
        }
    }
    printf("%c\n", sentence_terminator);

    return 0;
}