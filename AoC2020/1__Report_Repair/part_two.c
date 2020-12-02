#include <stdio.h>
#define INPUT_SIZE 200
#define TARGET 2020

int main() {
  int number, i, k, l;
  int ninput[INPUT_SIZE];
  FILE *fp;

  fp = fopen("input.txt", "r");

  int j = 0;
  while (fscanf(fp, "%d", &number) != EOF) {
    ninput[j++] = number;
  }

  for (i = 0; i < INPUT_SIZE - 2; ++i) {
    for (k = i + 1; k < INPUT_SIZE - 1; ++k) {
      for (l = k + 1; l < INPUT_SIZE; ++l) {
        if (ninput[i] + ninput[k] + ninput[l] == TARGET) {
            printf("%d\n", ninput[i]);
            printf("%d\n", ninput[k]);
            printf("%d\n", ninput[l]);
        }

      }
    }
  }

  fclose(fp);
}
