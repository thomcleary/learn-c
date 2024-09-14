/*
Modify 07/05.c so that the scrabble values of the letters are stored in an array
The array will have 26 elements, corresponding to the 26 letters of the alphabet
For example, element 0 will store 1, because the scrabble value of A is 1
As each character of the input word is read, the program will use the array to determine the value of that character
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    const char letter_values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    char ch;
    int value = 0;

    printf("Enter a word: ");

    while ((ch = toupper(getchar())) != '\n')
    {
        value += letter_values[ch - 'A'];
    }

    printf("Scrabble value: %d\n", value);

    return 0;
}