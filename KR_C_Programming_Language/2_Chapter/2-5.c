#include <stdio.h>
#include <string.h>

int any(char *s1, char *s2);

int main() {
  char s1[] = "hello\n";
  char s2[] = "world\n";
  int response = any(s1, s2);
  printf("Line 1: %s", s1);
  printf("Line 2: %s", s2);
  printf("occurance: %d\n", response);
}

int any(char *s1, char *s2) {
  char current_char;
  int counter = 1;
  int final = -1;
  while(*s1 != '\0') {
    current_char = *s1; 
    for (int i = 0; i < strlen(s2); ++i) {
      if (s2[i] == current_char) {
        final = counter;
        break;
      }
    }
    if (final != -1)
      break;
    counter++;
    s1++;
  }
  return final;
}
