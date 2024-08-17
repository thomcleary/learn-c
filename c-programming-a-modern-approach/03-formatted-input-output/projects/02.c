#include <stdio.h>

int main(void)
{
    int item_number;
    float unit_price;
    int purchase_month, purchase_day, purchase_year;

    printf("Enter item number: ");
    scanf("%d", &item_number);

    printf("Enter unit price: ");
    scanf("%f", &unit_price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &purchase_month, &purchase_day, &purchase_year);

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("    \t\tPrice\t\tDate\n");
    printf("%-d\t\t$%7.2f\t%d/%d/%d\n", item_number, unit_price, purchase_month, purchase_day, purchase_year);

    return 0;
}