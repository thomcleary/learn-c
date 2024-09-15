/*
Write a program that simulates the game of craps

Write your program as 3 functions:

int main(void);
int roll_dice(void);
bool play_game(void);
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0, losses = 0;
    char play_again;

    srand((unsigned)time(NULL));

    do
    {
        if (play_game())
        {
            printf("You win!\n");
            wins++;
        }
        else
        {
            printf("You lose!\n");
            losses++;
        }

        printf("\nPlay again? ");
        scanf(" %c", &play_again);
        printf("\n");
    } while (toupper(play_again) == 'Y');

    printf("Wins: %d Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    int dice1 = (rand() % 6) + 1;
    int dice2 = (rand() % 6) + 1;

    return dice1 + dice2;
}

bool play_game(void)
{
    int roll = roll_dice();

    printf("You rolled: %d\n", roll);

    if (roll == 7 || roll == 11)
    {
        return true;
    }
    else if (roll == 2 || roll == 3 || roll == 12)
    {
        return false;
    }

    int point = roll;
    printf("Your point is %d\n", point);

    while (true)
    {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == point)
        {
            return true;
        }

        if (roll == 7)
        {
            return false;
        }
    }
}