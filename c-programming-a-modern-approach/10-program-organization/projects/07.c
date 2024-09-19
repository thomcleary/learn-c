/*
Write a program that prompts the user for a number and then displays the number,
using characters to simulate the effect of a seven-segment display

Enter a number: 491-9014
     _       _   _
|_| |_|  |  |_| | |  |  |_|
  |  _|  |   _| |_|  |    |

Characters other than digits should be ignored
Write the program so that the maximum numbers of digits is controlled by a macro named MAX_DIGITS, which has the value of 10
If the number contains more than this number of digits, the extra digits are ignored
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGITS_ROWS (int)(sizeof(digits) / sizeof(digits[0]))
#define DIGITS_COLS (int)(sizeof(digits[0]) / sizeof(digits[0][0]))

const int segments[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

char example_digits[3][4] = {
    {' ', ' ', ' ', ' '},
    {'|', '_', '|', ' '},
    {' ', ' ', '|', ' '},
};

char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
  clear_digits_array();

  char ch;
  int num_digits = 0;

  printf("Enter a number: ");

  while (num_digits < MAX_DIGITS && (ch = getchar()) != '\n')
  {
    if (!isdigit(ch))
    {
      continue;
    }

    process_digit(ch - '0', num_digits);

    num_digits++;
  }

  print_digits_array();

  return 0;
}

void clear_digits_array(void)
{
  for (int i = 0; i < DIGITS_ROWS; i++)
  {
    for (int j = 0; j < DIGITS_COLS; j++)
    {
      digits[i][j] = ' ';
    }
  }
}

void process_digit(int digit, int position)
{
  int offset = position * 4;

  if (segments[digit][0])
  {
    digits[0][offset + 1] = '_';
  }

  if (segments[digit][1])
  {
    digits[1][offset + 2] = '|';
  }

  if (segments[digit][2])
  {
    digits[2][offset + 2] = '|';
  }

  if (segments[digit][3])
  {
    digits[2][offset + 1] = '_';
  }

  if (segments[digit][4])
  {
    digits[2][offset] = '|';
  }

  if (segments[digit][5])
  {
    digits[1][offset] = '|';
  }

  if (segments[digit][6])
  {
    digits[1][offset + 1] = '_';
  }
}

void print_digits_array(void)
{
  for (int i = 0; i < DIGITS_ROWS; i++)
  {
    for (int j = 0; j < DIGITS_COLS; j++)
    {
      printf("%c", digits[i][j]);
    }
    printf("\n");
  }
}
