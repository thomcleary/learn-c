/*
Write a B1FF filter, that reads a mesage entered by the user and translates it into B1FF speak
Your program should convert the message to upper-case letters,
substitute certain digits for certain letters
A-4, B-8, E-3, I-1, O-0, S-5
and then append 10 or so exclamation marks
*/

#include <ctype.h>
#include <stdio.h>

#define MESSAGE_MAX_LENGTH 1024
#define MESSAGE_LENGTH (int)(sizeof(message) / sizeof(message[0]))

int main(void)
{
    char message[MESSAGE_MAX_LENGTH];

    printf("Enter a message: ");

    int i = 0;
    char ch;

    while (i < MESSAGE_LENGTH && (ch = getchar()) != '\n')
    {
        message[i] = ch;
        i++;
    }

    if (i < MESSAGE_LENGTH)
    {
        message[i] = '\n';
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < MESSAGE_LENGTH; i++)
    {
        char ch = toupper(message[i]);

        if (ch == '\n')
        {
            break;
        }

        switch (ch)
        {
        case 'A':
            ch = '4';
            break;
        case 'B':
            ch = '8';
            break;
        case 'E':
            ch = '3';
            break;
        case 'I':
            ch = '1';
            break;
        case 'O':
            ch = '0';
            break;
        case 'S':
            ch = '5';
            break;
        }

        printf("%c", ch);
    }

    printf("!!!!!!!!!\n");

    return 0;
}