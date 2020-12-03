#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT_SIZE 100

FILE *file_ptr(char *file) {
  FILE *fp;
  fp = fopen(file, "r");
  return fp;
}

int count_lines(char *file) {
  FILE *fp;
  char c;
  int count = 0;
  int line = 0;

  fp = file_ptr(file);
  while ((c = getc(fp)) != EOF) {
    if (c == '\n') {
      count++;
    }
  }
  fclose(fp);

  return count;
}

int **init_arr(int file_len) {
  int **hill;
  int i;

  hill = malloc(sizeof(int*)*file_len);
  for (i = 0; i < file_len; i++) {
    hill[i] = calloc(file_len*file_len, sizeof(int) * file_len);
  }

  return hill;
}

void init_snowy_hill(int **arr, char *file, int file_len) { 
  char buffer[MAX_INPUT_SIZE];
  FILE *fp = file_ptr(file);
  int c;
  int i = 0;
  int j = 0;
  int k = 0;

  while ((c = fgetc(fp)) != EOF) {
    if (c == '\n') {
      for (k = 0; k < (file_len*file_len); k++) {
        if (buffer[i] == 0) i == 0;
        arr[j][k] = buffer[i++];
      }
      memset(buffer, 0, MAX_INPUT_SIZE);
      i = 0;
      j++;
    } else buffer[i++] = (char)c;
  }
  fclose(fp);
}

unsigned long ride_snowy_hill(int **arr, int file_len, int right, int down) {
  int x = 0;
  int y = 0;
  unsigned long tree_count = 0;

  for (x = 0; x < file_len; x+=down) {
    if (arr[x][y] == '#') tree_count++;
    y += right;
  }

  return tree_count;
}


int main(int argc, char **argv) {
  char *file = argv[1];
  int file_len = count_lines(file);
  int **hill = init_arr(file_len);
  init_snowy_hill(hill, file, file_len);
  printf("Part 1: %lu\n", ride_snowy_hill(hill, file_len, 3, 1));

  return 0;
}
