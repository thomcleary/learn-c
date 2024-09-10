/*
Modify 06/11.c so that the program continues adding terms until
the current term becomes less than epsilon
where epsilon is a small (floating-point) number entered by the user
*/

#include <stdio.h>

int main(void)
{
    float epsilon;

    printf("Approximate e\n");
    printf("Enter epsilon (< 1.00): ");
    scanf("%f", &epsilon);

    float e = 1.00f;

    int i = 1;
    int factor = 1;
    float term = 1.00f / (factor);

    while (term >= epsilon)
    {
        e += term;

        i++;
        factor *= i;
        term = 1.00f / (factor);
    }

    printf("e (%d terms): %.5f\n", i - 1, e);

    return 0;
}