#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("Char Min/Max: %d:%d\n", CHAR_MIN, CHAR_MAX);
  printf("Short Min/Max: %d:%d\n", SHRT_MIN, SHRT_MAX);
  printf("Int Min/Max: %d:%d\n", INT_MIN, INT_MAX);
  printf("Long Min/Max: %ld:%ld\n", LONG_MIN, LONG_MAX);
  printf("Unsigned Char, Short, Int, Long: %d:%d:%u:%lu\n", UCHAR_MAX, USHRT_MAX, UINT_MAX, ULONG_MAX);
  printf("\n");
  printf("float min/max: %.10e:%.10e\n", FLT_MIN, FLT_MAX);
  printf("double min/max: %.10e:%.10e\n", DBL_MIN, DBL_MAX);
}
