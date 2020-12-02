#include <stdio.h>
#define INPUT_SIZE 200
#define TARGET 2020

int main() {
  int number, i, k;
  int ninput[INPUT_SIZE];
  FILE *fp;

  fp = fopen("input.txt", "r");

  int j = 0;
  while (fscanf(fp, "%d", &number) != EOF) {
    ninput[j++] = number;
  }

  for (i = 0; i < INPUT_SIZE; ++i) {
    for (k = i + 1; k < INPUT_SIZE; ++k) {
      if (ninput[i] + ninput[k] == TARGET) {
        printf("%d\n", ninput[i] * ninput[k]);
      }
    }
  }

  fclose(fp);
}
