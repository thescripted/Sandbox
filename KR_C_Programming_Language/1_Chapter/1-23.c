// Remove all comments from a C program.
//
// "quoted strings" and character constants should also be
// Handled properly...
//

#include <stdio.h>
#define MAX_SIZE 300

int read_line(char input[], int size);
void parse_line(char input[]);
void write_line(char input[], char output[]);
int is_comment(char buffer[]);

int main() { // In-line comments like this one should be removed as well.
  int c;
  char input[MAX_SIZE];
  char output[MAX_SIZE];
  while (read_line(input, MAX_SIZE) > 0) {
    parse_line(input);
    write_line(input, output);
  }
}

// read into input the current line. return line size.
int read_line(char input[], int size) {
  int i, c;
  for (i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    input[i] = c;
  }
  if (c == '\n') {
    input[i] = c;
    i++;
  }
  input[i] = '\0';
  return i;
}

// parses out comments in a C file.
void parse_line(char input[]) {
  int i;
  char buffer[2];
  int single_quote, double_quote;

  single_quote = 0;
  double_quote = 0;

  buffer[0] = ' ';
  buffer[1] = ' ';

  for (i = 0; input[i] != '\0'; ++i) {
    buffer[0] = buffer[1];
    buffer[1] = input[i];
    if (is_comment(buffer) == 1) {
      input[i-1] = '\0';
      break;
    }
  }
}

int is_comment(char buffer[]) {
  if (buffer[0] == '/' && buffer[1] == '/') {
    return 1;
  }
  return 0;
}

void write_line(char input[], char output[]) {
  int i;

  i = 0;
  while ((output[i] = input[i]) != '\0') {
    ++i;
  }
  printf("%s", output);
}
