/*
Modify the repdigit.c example so that it shows which digits (if any) were repeated
*/

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int digit_count[10] = {0};
    bool repeat_found = false;
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0)
    {
        digit = n % 10;
        digit_count[digit]++;
        n /= 10;

        if (!repeat_found && digit_count[digit] > 1)
        {
            repeat_found = true;
        }
    }

    if (!repeat_found)
    {
        printf("No repeated digit\n");
    }
    else
    {
        printf("Repeated digits: ");
        for (int i = 0; i < sizeof(digit_count) / sizeof(digit_count[0]); i++)
        {
            if (digit_count[i] > 1)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}