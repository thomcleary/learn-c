/* Modify 02.c so that it promts the user to enter the radius of a sphere */

#include <math.h>
#include <stdio.h>

int main(void)
{
    float radius;

    printf("Sphere radius: ");
    scanf("%f", &radius);

    int radius_cubed = radius * radius * radius;
    float volume = (4.0f / 3.0f) * M_PI * radius_cubed;

    printf("Volume of a sphere with %.2f meter radius: %.2f", radius, volume);

    return 0;
}