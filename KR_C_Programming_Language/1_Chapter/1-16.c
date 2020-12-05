#include <stdio.h>
#define MAX_SIZE 100

int get_line(char s[], int lim);
void copy(char to[], char from[]);

int main() {
  int curr;
  int max;
  char longest[MAX_SIZE];
  char current[MAX_SIZE];

  max = 0;
  while ((curr = get_line(current, MAX_SIZE)) > 0) {
    if (curr > max) {
      max = curr;
      copy(longest, current);
    }
  }

  if (max > 0)
    printf("longest line: %s", longest);
  printf("\nmax size: %d\n", max);
}

int get_line(char s[], int lim) {
  int i, c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[i] = c;
    }
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
