/*
Modify 08/09.c so that it includes the following functions

void generate_random_walk(char walk[10][10])
void print_array(char walk[10][10])
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

void generate_random_walk(char walk[MAP_SIZE][MAP_SIZE]);
void print_array(char walk[MAP_SIZE][MAP_SIZE]);

int main(void)
{
    char walk[MAP_SIZE][MAP_SIZE];

    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[MAP_SIZE][MAP_SIZE])
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            walk[i][j] = '.';
        }
    }

    srand((unsigned)time(NULL));

    char step = 'A';
    int x = 0, y = 0;

    walk[y][x] = step;
    step++;

    while (step <= 'Z')
    {
        bool is_up_blocked = (y - 1) < 0 || walk[y - 1][x] != '.';
        bool is_down_blocked = (y + 1) >= MAP_SIZE || walk[y + 1][x] != '.';
        bool is_left_blocked = (x - 1) < 0 || walk[y][x - 1] != '.';
        bool is_right_blocked = (x + 1) >= MAP_SIZE || walk[y][x + 1] != '.';

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

        if (step_is_outside_map || walk[y_step][x_step] != '.')
        {
            continue;
        }

        walk[y_step][x_step] = step;

        step++;
        x = x_step;
        y = y_step;
    }
}

void print_array(char walk[MAP_SIZE][MAP_SIZE])
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            printf("%c ", walk[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}
