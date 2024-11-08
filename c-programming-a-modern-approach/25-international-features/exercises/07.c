/*
Modify the program fragment in Exercise 6 by replacing as many tokens as
possible by digraphs and macros defined in <iso646.h>
*/

#include <ctype.h>
#include <iso646.h>
#include <stdio.h>

#define KEY 0

int main(void) {
  char orig_char, new_char;

  while ((orig_char = getchar()) not_eq EOF) <%
    new_char = orig_char xor KEY;
    if (isprint(orig_char) and isprint(new_char)) <%
      putchar(new_char);
    %> else <%
      putchar(orig_char);
    %>
  }

  return 0;
}
