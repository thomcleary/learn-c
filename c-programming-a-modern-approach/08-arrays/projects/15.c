/*
Write a program that encrypts a message using a Caesar cipher
You may assume the message does not exceed 80 characters
*/

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char message[80];
    int shift_amount;

    printf("Enter a message to be encrypted: ");

    int num_chars = 0;
    for (; num_chars < (int)(sizeof(message) / sizeof(message[0])); num_chars++)
    {
        char next = getchar();

        if (next == '\n')
        {
            break;
        }

        message[num_chars] = next;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift_amount);

    printf("Encrypted message: ");
    for (int i = 0; i < num_chars; i++)
    {
        char ch = message[i];

        if (isalpha(ch))
        {
            char a_ch = isupper(ch) ? 'A' : 'a';
            putchar((((ch - a_ch) + shift_amount) % 26) + a_ch);
        }
        else
        {
            putchar(ch);
        }
    }

    printf("\n");

    return 0;
}