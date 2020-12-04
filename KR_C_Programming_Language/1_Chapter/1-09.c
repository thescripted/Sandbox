#include <stdio.h>

int main() {
  int c, dup;

  dup = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      dup++;
      if (dup <= 1) {
        putchar(c);
      }
    } else {
      dup = 0;
      putchar(c);
    }
  }
}
