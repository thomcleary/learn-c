/*
Write a program that calculates the average word length for a sentence
Consider punctuation to be part of the word to which it is attached
Display the average word length to one decimal place
*/

#include <stdio.h>

int main(void)
{
    printf("Enter a sentence: ");

    int word_count = 1;
    int letter_count = 0;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch != ' ')
        {
            letter_count++;
        }
        else
        {
            word_count++;
        }
    }

    printf("Average word length: %f\n", letter_count == 0 ? 0 : ((float)letter_count) / word_count);

    return 0;
}