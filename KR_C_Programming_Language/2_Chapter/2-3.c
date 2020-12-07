#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ARR_LIMIT 100

unsigned int htoi(char* s);
int get_line(char* line, int limit);

int main() {
  char line[ARR_LIMIT];
  int i = get_line(line, ARR_LIMIT);
  printf("%s\n", line);
  unsigned int transform;
  if (i > 0) {
    transform = htoi(line);
    printf("%s has been converted into %u\n", line, transform);
  }

}

unsigned int htoi(char* s) {
  unsigned int total = 0;
  unsigned int append = 0;
  int current;
  int prefix = 0;
  if (s && s + 1 && (*(s+1) == 'x' || *(s+1) == 'X')) {
    prefix += 2;
  }

  s = s + prefix;
  while (isxdigit(*s)) {
    if (isdigit(*s))
      current = *s - '0';
    else
      current = 10 + toupper(*s) - 'A';
    total = total * 16 + current;
    s++;
  }
  return total;
}

int get_line(char* line, int limit) {
  int c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (i < (limit - 1))
      line[i++] = c;
  }
  line[i] = '\0';
  return i;
}
