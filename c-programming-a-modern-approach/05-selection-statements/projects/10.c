/*
Using a switch statement, write a program that converts a numerical grade into a letter grade
*/

#include <stdio.h>

int main(void)
{
    int grade;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    int tens_digit = grade / 10;

    switch (tens_digit)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("F\n");
        break;
    case 6:
        printf("D\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 8:
        printf("B\n");
        break;
    default:
        printf("A\n");
        break;
    }

    return 0;
}