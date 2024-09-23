/*
Modify the 08/deal.c example so that it prints the full names of the cards it deals
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven",
                           "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    const char *suits[] = {"clubs", "diamonds", "hearts", "spades"};

    srand((unsigned)time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:\n");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANKS;
        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s of %s\n", ranks[rank], suits[suit]);
        }
    }

    return 0;
}