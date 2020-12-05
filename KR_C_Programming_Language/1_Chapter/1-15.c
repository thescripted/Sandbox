#include <stdio.h>

float fahrtocelsius(float degree);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahrenheit-Celsius table\n");
  while (fahr < upper) {
    celsius = fahrtocelsius(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float fahrtocelsius(float degree) {
  return (5.0/9.0) * (degree - 32);
}
