#include <stdio.h>

int main() {
  int lower, upper, step;
  float fahr, celsius;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  while (celsius <= upper) {
    fahr = 32 + (celsius * 9.0/5.0);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
