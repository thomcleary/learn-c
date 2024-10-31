/*
Exercise 4
Give a C string literal that represents each of the following phrases.
Assume that characters are represented by single-byte Latin-1 characters
(You'll need to look up the Latin-1 code points for these characters)

For example the phrase déjà vu could be represented by the string "d\xe9j\xe0
vu"

(a) Côte d'Azur
(b) crème brûlée
(c) crème fraîche
(d) Fahrvergnügen
(e) tête-à-tête

Exercise 5
Repeat Exercise 4, this time using the UTF-8 multibyte encoding.
For example, the phrase déjà vu could be represented by the string
"d\xc3\xa9j\xc3\xa0 vu"
*/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void) {
  // (a) Côte d'Azur
  // ô - U+00F4
  // U+uvwxyz: y=F, z=4
  // 110x_xxyy 10yy_zzzz
  // 1100_0011_1011_0100
  // C3_B4
  char *a = "C\xc3\xb4te d'Azur";

  // (b) crème brûlée
  // è - U+00E8
  // U+uvwxyz: y=E, z=8
  // 110x_xxyy 10yy_zzzz
  // 1100_0011 1010_1000
  // C3_A8
  //
  // û - U+00FB
  // U+uvwxyz: y=F, z=B
  // 110x_xxyy 10yy_zzzz
  // 1100_0011_1011_1011
  // C3_BB
  //
  // é - U+00E9
  // U+uvwxyz: y=E, z=9
  // 110x_xxyy 10yy_zzzz
  // 1100_0011 1010_1001
  // C3_A9
  char *b = "cr\xc3\xa8me br\xc3\xbbl\xc3\xa9"
            "e";

  // (c) crème fraîche
  // è - see (b)
  //
  // î - U+00EE
  // U+uvwxyz: y=E, z=E
  // 110x_xxyy 10yy_zzzz
  // 1100_0011 1010_1110
  // C3_AE
  char *c = "cr\xc3\xa8me fra\xc3\xae"
            "che";

  // (d) Fahrvergnügen
  // ü - U+00FC
  // U+uvwxyz: y=F, z=C
  // 110x_xxyy 10yy_zzzz
  // 1100_0011_1011_1100
  // C3_BC
  char *d = "Fahrvergn\xc3\xbcgen";

  // (e) tête-à-tête
  // ê - U+00EA
  // U+uvwxyz: y=E, z=A
  // 110x_xxyy 10yy_zzzz
  // 1100_0011_1010_1010
  // C3_AA
  //
  // à - U+00E0
  // U+uvwxyz: y=E, z=0
  // 110x_xxyy 10yy_zzzz
  // 1100_0011_1010_0000
  // C3_A0
  char *e = "t\xc3\xaate-\xc3\xa0-t\xc3\xaate";

  printf("(a): %s\n", a);
  printf("(b): %s\n", b);
  printf("(b): %s\n", c);
  printf("(d): %s\n", d);
  printf("(e): %s\n", e);

  return 0;
}
