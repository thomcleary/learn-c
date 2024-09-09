#include <stdio.h>

int main(void)
{
    long long ean;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%12lld", &ean);

    int l = ean % 10;

    ean /= 10;
    int k = ean % 10;

    ean /= 10;
    int j = ean % 10;

    ean /= 10;
    int i = ean % 10;

    ean /= 10;
    int h = ean % 10;

    ean /= 10;
    int g = ean % 10;

    ean /= 10;
    int f = ean % 10;

    ean /= 10;
    int e = ean % 10;

    ean /= 10;
    int d = ean % 10;

    ean /= 10;
    int c = ean % 10;

    ean /= 10;
    int b = ean % 10;

    ean /= 10;
    int a = ean % 10;

    int first_sum = b + d + f + h + j + l;
    int second_sum = a + c + e + g + i + k;

    int check_digit = 9 - ((((first_sum * 3) + second_sum) - 1) % 10);

    printf("Check digit: %d\n", check_digit);

    return 0;
}