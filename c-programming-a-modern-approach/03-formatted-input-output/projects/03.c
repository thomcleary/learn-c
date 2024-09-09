/*
Write a program that breaks down an ISBN entered by a user
*/

#include <stdio.h>

int main(void)
{
    int gs1_prefix, group_identifier, publisher_code, item_number, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);

    printf("GS1 prefix: %d\n", gs1_prefix);
    printf("Group identifier: %d\n", group_identifier);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item numer: %d\n", item_number);
    printf("Check digit: %d\n", check_digit);

    return 0;
}