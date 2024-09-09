/*
Write a program that finds the largest and smallest of four integers entered by the user
(use as few if statements as possible, 4 is sufficient)
*/

#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    int l1, l2, s1, s2;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a > b)
    {
        l1 = a;
        s1 = b;
    }
    else
    {
        l1 = b;
        s1 = a;
    }

    if (c > d)
    {
        l2 = c;
        s2 = d;
    }
    else
    {
        l2 = d;
        s2 = c;
    }

    printf("Largest: %d\n", l1 > l2 ? l1 : l2);
    printf("Smallest: %d\n", s1 < s2 ? s1 : s2);

    return 0;
}