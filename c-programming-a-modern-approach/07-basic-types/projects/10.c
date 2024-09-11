/*
Write a program that counts the number of vowels in a sentence
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char ch;
    int vowels = 0;

    printf("Enter a sentence: ");

    while ((ch = toupper(getchar())) != '\n')
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
    }

    printf("Your sentence contains %d vowels\n", vowels);

    return 0;
}