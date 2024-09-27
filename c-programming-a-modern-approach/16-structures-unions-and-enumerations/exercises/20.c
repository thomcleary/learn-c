/*
Suppose that the direction variable is declared in the following way
*/

enum
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} direction;

/*
Let x and y be int variables.

Write a switch statement that tests the value of direction,
incrementing x if direction is EAST,
decrementing x if the direction is WEST,
incrementing y if the direction is SOUTH,
decrementing y if the direction is NORTH
*/

#include <stdio.h>

int main(void)
{
    int x = 0, y = 0;

    direction = NORTH;

    switch (direction)
    {
    case EAST:
        x++;
        break;
    case WEST:
        x--;
        break;
    case SOUTH:
        y++;
        break;
    case NORTH:
        y--;
        break;
    }

    printf("(x,y): (%d,%d)\n", x, y);

    return 0;
}