/*
Modify 04.c so that the polynomial is evaluated using the following formula
((((3x + 2)x - 5)x - 1)x + 7)x - 6
*/

#include <math.h>
#include <stdio.h>

int main(void)
{
    float x;
    printf("Enter 'x': ");
    scanf("%f", &x);

    // float value = (((((((((3 * x) + 2) * x) - 5) * x) - 1) * x) + 7) * x) - 6;
    float value = 3;
    value *= x;
    value += 2;
    value *= x;
    value -= 5;
    value *= x;
    value -= 1;
    value *= x;
    value += 7;
    value *= x;
    value -= 6;

    printf("Value: %.3f", value);

    return 0;
}