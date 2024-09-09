/* Write a program that computes the volume of a sphere with 10 meter radius */

#include <math.h>
#include <stdio.h>

#define RADIUS 10

int main(void)
{
    int radius_cubed = RADIUS * RADIUS * RADIUS;
    float volume = (4.0f / 3.0f) * M_PI * radius_cubed;

    printf("Volume of a sphere with 10 meter radius: %f", volume);

    return 0;
}