/*
Modify 08/15.c so that it includes the following function

void encrypt(char *message, int shift);

The function expects message to point to a string containing the message to be encrypted;
shift represents the amount by which each letter in the message is to be shifted.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MSG_MAX_LEN 80

void encrypt(char *message, int shift);

int main(void)
{
    char message[MSG_MAX_LEN + 1];

    printf("Enter a message to be encrypted: ");
    fgets(message, sizeof(message), stdin);

    int message_length = strlen(message);
    char *last_ch = message + (message_length - 1);

    if (message_length > 0 && *last_ch == '\n')
    {
        *last_ch = '\0';
    }

    int shift_amount;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    encrypt(message, shift_amount);

    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    while (*message)
    {
        if (isalpha(*message))
        {
            char a_ch = isupper(*message) ? 'A' : 'a';
            *message = (((*message - a_ch) + shift) % 26) + a_ch;
        }

        message++;
    }
}
