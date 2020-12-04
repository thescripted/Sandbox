#include <stdio.h>
#define IN 1
#define OUT 0
#define HISTO_SIZE 20

int main() {
  int histo[HISTO_SIZE], c, wlcount;
  int state;
  int i;

  for (i = 0; i < HISTO_SIZE; ++i)
    histo[i] = 0;

  state = OUT;
  wlcount = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      state = OUT;
      if (wlcount <= HISTO_SIZE && wlcount > 0)
        histo[wlcount - 1]++;
      wlcount = 0;
    } else {
      state = IN;
      wlcount++;
    }
  }

  for (i = 0; i < HISTO_SIZE; ++i) {
    printf("%d: ", i);
    while(histo[i] > 0) {
      printf("#");
      histo[i]--;
    }
    printf("\n");
    }
}
