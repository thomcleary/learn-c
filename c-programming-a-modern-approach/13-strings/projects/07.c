/*
Modify 05/11.c so that it uses arrays containing pointers to strings instead of switch statements.
For example, instead of using a switch statement to print the word for the first digit,
use the digit as an index into an array that contains the strings "twenty", "thirty", and so forth
*/

#include <stdio.h>

int main(void)
{
    const char *ones_strings[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const char *teens_strings[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char *tens_strings[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    int n;

    printf("Enter a two-digit number: ");
    scanf("%2d", &n);

    printf("You entered the number ");

    if (n < 20)
    {
        printf("%s", teens_strings[n - 10]);
    }
    else
    {
        int tens = n / 10;
        int ones = n % 10;

        printf("%s", tens_strings[tens - 2]);

        if (ones > 0)
        {
            printf("-%s", ones_strings[ones - 1]);
        }
    }

    printf(".\n");

    return 0;
}