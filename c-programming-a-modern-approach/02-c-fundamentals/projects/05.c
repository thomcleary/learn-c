/* Calculates 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */

#include <math.h>
#include <stdio.h>

int main(void)
{
    float x;
    printf("Enter 'x': ");
    scanf("%f", &x);

    float value = 3 * pow(x, 5);
    value += 2 * pow(x, 4);
    value -= 5 * pow(x, 3);
    value -= pow(x, 2);
    value += 7 * x;
    value -= 6;

    printf("Value: %.3f", value);

    return 0;
}