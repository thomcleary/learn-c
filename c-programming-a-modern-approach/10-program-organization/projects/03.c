/*
Remove the num_in_rank, num_in_suit, and card_exists arrays from the poker.c example
Have the program store the cards in a 5x2 array instead.
Each row of the array will represent a card, for example
hand[0][0] will store the rank of the first card and hand[0][1] will store the suit
*/

/* poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

#include <stdbool.h> /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
bool card_exists(int rank, int suit);
void sort_hand_by_rank(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    for (;;)
    {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (int card = 0; card < NUM_CARDS; card++)
    {
        hand[card][0] = -1;
        hand[card][1] = -1;
    }

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch)
        {
        case '0':
            exit(EXIT_SUCCESS);
        case '2':
            rank = 0;
            break;
        case '3':
            rank = 1;
            break;
        case '4':
            rank = 2;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 4;
            break;
        case '7':
            rank = 5;
            break;
        case '8':
            rank = 6;
            break;
        case '9':
            rank = 7;
            break;
        case 't':
        case 'T':
            rank = 8;
            break;
        case 'j':
        case 'J':
            rank = 9;
            break;
        case 'q':
        case 'Q':
            rank = 10;
            break;
        case 'k':
        case 'K':
            rank = 11;
            break;
        case 'a':
        case 'A':
            rank = 12;
            break;
        default:
            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch)
        {
        case 'c':
        case 'C':
            suit = 0;
            break;
        case 'd':
        case 'D':
            suit = 1;
            break;
        case 'h':
        case 'H':
            suit = 2;
            break;
        case 's':
        case 'S':
            suit = 3;
            break;
        default:
            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists(rank, suit))
            printf("Duplicate card; ignored.\n");
        else
        {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }

    sort_hand_by_rank();
}

bool card_exists(int rank, int suit)
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        if (rank == hand[i][0] && suit == hand[i][1])
        {
            printf("i %d\n", i);
            return true;
        }
    }

    return false;
}

void sort_hand_by_rank(void)
{
    for (int cards = NUM_CARDS; cards > 1; cards--)
    {
        int high_pos = 0;

        for (int i = 1; i < cards; i++)
        {
            if (hand[i][0] > hand[high_pos][0])
            {
                high_pos = i;
            }
        }

        int rank_to_swap = hand[cards - 1][0];
        int suit_to_swap = hand[cards - 1][1];

        hand[cards - 1][0] = hand[high_pos][0];
        hand[cards - 1][1] = hand[high_pos][1];
        hand[high_pos][0] = rank_to_swap;
        hand[high_pos][1] = suit_to_swap;
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void)
{
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush and straight */
    int prev_card_rank = hand[0][0];
    int first_card_suit = hand[0][1];
    for (int card = 1; card < NUM_CARDS; card++)
    {
        int curr_card_rank = hand[card][0];

        if (curr_card_rank != prev_card_rank + 1)
        {
            straight = false;
        }

        if (hand[card][1] != first_card_suit)
        {
            flush = false;
        }

        prev_card_rank = curr_card_rank;
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    int count = 1;
    int prev_rank = hand[0][0];
    for (int card = 1; card < NUM_CARDS; card++)
    {
        int rank = hand[card][0];

        if (rank == prev_rank)
        {
            count++;

            if (card + 1 < NUM_CARDS)
            {
                continue;
            }
        }

        switch (count)
        {
        case 2:
            pairs++;
            break;
        case 3:
            three = true;
            break;
        case 4:
            four = true;
            break;
        }

        count = 1;
        prev_rank = rank;
    }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
    if (straight && flush)
        printf("Straight flush");
    else if (four)
        printf("Four of a kind");
    else if (three &&
             pairs == 1)
        printf("Full house");
    else if (flush)
        printf("Flush");
    else if (straight)
        printf("Straight");
    else if (three)
        printf("Three of a kind");
    else if (pairs == 2)
        printf("Two pairs");
    else if (pairs == 1)
        printf("Pair");
    else
        printf("High card");

    printf("\n\n");
}