/*
Write a program that finds the "smallest" and "largest" in a series of words.
After the user enters the words, the program will determine which words would come first and last if the words were listed in dictionary order.
The program must stop accepting input when the user enters a four-letter word.
Assume that no word is more than 20 letters long.

An interactive session with the program might look like this:

Enter word: dog
Enter word: zebra
Enter word: rabbit
Enter word: cat
Enter word: fish

Smallest word: cat
Largest word: zebra
*/

#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

int main(void)
{
    char smallest_word[WORD_LEN + 1], largest_word[WORD_LEN + 1];
    char current_word[WORD_LEN + 1];

    printf("Enter word: ");
    scanf("%s", current_word);

    strcpy(smallest_word, strcpy(largest_word, current_word));

    while (strlen(current_word) != 4)
    {
        printf("Enter word: ");
        scanf("%s", current_word);

        if (strcmp(current_word, smallest_word) < 0)
        {
            strcpy(smallest_word, current_word);
        }
        else if (strcmp(current_word, largest_word) > 0)
        {
            strcpy(largest_word, current_word);
        }
    }

    printf("\n");
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}