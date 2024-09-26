/*
Let color be the following structure
*/

struct color
{
    int red;
    int green;
    int blue;
};

/*
(a) Write a declaration for a const variable named MAGENTA of type struct color
whose members have the values 255, 0 and 255 respectively

(b) (C99) Repeat part (a), but use a designated initializer that doesn't specify the value of green,
allowing it to default to 0.
*/

#include <stdio.h>

int main(void)
{
    const struct color MAGENTA = {.red = 255, .green = 0, .blue = 255};

    printf("(a) MAGENTA (r, g, b): (%d, %d, %d)\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    const struct color MAGENTA_2 = {.red = 255, .blue = 255};

    printf("(b) MAGENTA_2 (r, g, b): (%d, %d, %d)\n", MAGENTA_2.red, MAGENTA_2.green, MAGENTA_2.blue);

    return 0;
}