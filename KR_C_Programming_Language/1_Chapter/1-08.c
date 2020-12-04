#include <stdio.h>

int main() {
  int c, bl, tb, nl;
  
  bl = 0;
  tb = 0;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      nl++;
    }
    if (c == '\t') {
      tb++;
    }
    if (c == ' ') {
      bl++;
    }
  }

  printf("Blanks: %d\nTabs: %d\nNew Lines:%d\n", bl, tb, nl);
}
