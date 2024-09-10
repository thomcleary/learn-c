/*
Write a program that prompts the user to enter a number n
then prints all even squares between 1 and n
*/

#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1, j = 1; j <= n; i++, j = i * i)
    {
        if (j % 2 == 0)
        {
            printf("%d\n", j);
        }
    }

    return 0;
}