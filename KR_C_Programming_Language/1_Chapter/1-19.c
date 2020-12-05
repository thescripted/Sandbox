#include <stdio.h>

void reverse(char s[]);

int main() {
  char s[100];
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF) {
    s[i] = c;
    ++i;
  }
  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);
}

void reverse(char s[]) {
  int size, i;
  char tmp;

  size = 0;
  // get size of array
  while(s[size] != '\0')
    ++size;
  for (i = 0; i < (size - 1)/2 - 1; ++i) {
    char tmp = s[i];
    s[i] = s[size - 2 - i];
    s[size - 2 - i] = tmp;
  }
}
