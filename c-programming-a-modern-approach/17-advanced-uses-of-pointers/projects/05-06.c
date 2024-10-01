/*
Project 5
Write a program that sorts a series of words entered by the user:

Enter word: foo
Enter word: bar
Enter word: baz
Enter word:

In sorted order: bar baz foo

Assume that each word is no more than 20 characters long.
Stop reading when the user enters an empty word.
Store each word in a dynamically allocated string, using an array of pointers to keep track of the strings,
as in the `remind2.c` program.
After all words have been read, sort the array (using an technique) and then use a loop to print the words in sorted order.
*/

/*
Project 6
Use `qsort` to sort the array of pointers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20

int read_line(char str[], int n)
{
    int ch, i = 0;

    printf("Enter word: ");
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
}

int compare_words(const void *a, const void *b)
{
    return strcmp(*((char **)a), *((char **)b));
}

int main(void)
{
    char **words = NULL;

    char *w = malloc(sizeof(*w) * (WORD_LEN + 1));
    if (w == NULL)
    {
        printf("w: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    int word_count = 0;

    while ((read_line(w, WORD_LEN) != 0))
    {
        if (word_count == 0)
        {
            words = malloc(sizeof(*words));
            if (words == NULL)
            {
                printf("words: malloc failed\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            char **temp = realloc(words, sizeof(*words) * (word_count + 1));
            if (temp == NULL)
            {
                printf("words: realloc failed\n");
                break;
            }
            words = temp;
        }

        words[word_count] = w;

        w = malloc(sizeof(*w) * (WORD_LEN + 1));
        if (words == NULL)
        {
            printf("w: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        word_count++;
    }

    qsort(words, word_count, sizeof(*words), compare_words);

    printf("In sorted order: ");
    for (int i = 0; i < word_count; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Don't bother freeing anything since the program terminates
    return 0;
}