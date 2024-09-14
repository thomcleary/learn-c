/*
Write a program that generates a "random walk" across a 10x10 array
The array will contain characters (all '.' initially)
The program must randomly "walk" from element to element, always going up, down, left or right by one element
The elements visited by the program will be labeled with the letters A through Z in the order visited
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

int main(void)
{
    char map[MAP_SIZE][MAP_SIZE];

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = '.';
        }
    }

    srand((unsigned)time(NULL));

    char step = 'A';
    int x = 0, y = 0;

    map[y][x] = step;
    step++;

    while (step <= 'Z')
    {
        bool is_up_blocked = (y - 1) < 0 || map[y - 1][x] != '.';
        bool is_down_blocked = (y + 1) >= MAP_SIZE || map[y + 1][x] != '.';
        bool is_left_blocked = (x - 1) < 0 || map[y][x - 1] != '.';
        bool is_right_blocked = (x + 1) >= MAP_SIZE || map[y][x + 1] != '.';

        if (is_up_blocked && is_down_blocked && is_left_blocked && is_right_blocked)
        {
            break;
        }

        int direction = rand() % 4;

        int x_step = x;
        int y_step = y;

        switch (direction)
        {
        case 0:
            y_step -= 1;
            break;
        case 1:
            y_step += 1;
            break;
        case 2:
            x_step -= 1;
            break;
        case 3:
            x_step += 1;
            break;
        }

        bool step_is_outside_map = x_step >= MAP_SIZE || x_step < 0 || y_step >= MAP_SIZE || y_step < 0;

        if (step_is_outside_map || map[y_step][x_step] != '.')
        {
            continue;
        }

        map[y_step][x_step] = step;

        step++;
        x = x_step;
        y = y_step;
    }

    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}