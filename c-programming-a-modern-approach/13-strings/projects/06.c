/*
Improve the planet.c example by having it ignore case when comparing command line arguments with strings in the planets array
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

bool planet_equals(char *a, char *b);

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    int i, j;

    for (i = 1; i < argc; i++)
    {
        for (j = 0; j < NUM_PLANETS; j++)
        {
            if (planet_equals(argv[i], planets[j]))
            {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }

        if (j == NUM_PLANETS)
        {
            printf("%s is not a planet\n", argv[i]);
        }
    }

    return 0;
}

bool planet_equals(char *a, char *b)
{
    while (*a)
    {
        if (!(*b) || (toupper(*a) != toupper(*b)))
        {
            return false;
        }

        a++;
        b++;
    };

    return !(*b);
}
