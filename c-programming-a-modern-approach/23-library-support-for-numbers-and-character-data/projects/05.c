/*
Suppose that money is deposited into a savings account and left for t years.
Assume that the annual interest rate is r and that interest is compounded
continously. The formula, A(t) = P(e^(rt)) can be used to calculate the final
value of the account, where P is the original amount deposited.

For example, $1000 left on deposit for 10 years at 6% interest would be worth
$1000 x e^(.06 * 10) = $1,822.12

Write a program that displays the result of this calculation after prompting the
user to enter the original amount deposited, the interest rate, and the number
of years
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: ./05 principal rate term\n");
    exit(EXIT_FAILURE);
  }

  long double principal = strtold(argv[1], NULL);
  long double interest_rate = strtold(argv[2], NULL) / 100;
  unsigned int term = strtol(argv[3], NULL, 10);

  long double final_value = principal * expl(interest_rate * term);

  printf("$%.2Lf\n", final_value);

  return 0;
}
