/*
Modify the following program fragment by replacing as many characters as
possible by trigraphs

while ((orig_char = getchar()) != EOF) {
  new_char = orig_char ^ KEY;
  if (isprint(orig_char) && isprint(new_char)) {
    putchar(new_char);
  } else {
    putchar(orig_char);
  }
}
*/

#include <ctype.h>
#include <stdio.h>

#define KEY 0

int main(void) {
  char orig_char, new_char;

  while ((orig_char = getchar()) != EOF) ??<
    new_char = orig_char ??' KEY; 
    if (isprint(orig_char) && isprint(new_char)) ??< 
      putchar( new_char);
    ??> else ??<
      putchar(orig_char);
  ??>
}

  return 0;
}
