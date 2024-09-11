/*
Modify square2.c from /06 so that it pauses after every 24 squares and displays the message
Press Enter to continue...
After displaying the message, the program should use getchar to read a character.
getchar won't allow the program to continue until the user presses the Enter key
 */

#include <stdio.h>

int main(void)
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar(); // Read the last newline char

    for (i = 1; i <= n; i++)
    {
        printf("%10d%10d\n", i, i * i);

        if (i % 24 == 0)
        {
            printf("Press Enter to continue...");
            while (getchar() != '\n')
            {
                ;
            }
        }
    }

    return 0;
}