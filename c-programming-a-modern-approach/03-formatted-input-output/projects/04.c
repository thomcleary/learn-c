/*
Write a program that prompts the user to enter a telephone number in the form
(xxx) xxx-xxxx
and then displays the number in the form
xxx.xxx.xxxx
*/

#include <stdio.h>

int main(void)
{
    int area_code, prefix, suffix;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &area_code, &prefix, &suffix);

    printf("You entered %d.%d.%d\n", area_code, prefix, suffix);

    return 0;
}