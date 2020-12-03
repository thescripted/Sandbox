#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *fp = fopen("input.txt", "r");
  char *search, line[100];
  int current;
  int start, end, counter;
  int carry = 0;
  int valid = 0;
  
    while (fgets(line, 100, fp) != NULL) {
      int found = 0;
      counter = 0;

      start = line[0] - '0';

      if (isdigit(line[1])) { 
        start = start * 10 + (line[1] - '0');
        carry++;
      }

      end = line[2 + carry] - '0';

      if (isdigit(line[3 + carry])) {
        end = end * 10 + (line[3 + carry] - '0');
        carry++;
      }

      search = &line[4 + carry];
      current = 7 + carry;

      if (*search == line[start + current - 1]) {
        found++;
      }

      if (*search == line[end + current - 1]) {
        found++;
      }


      if (found == 1) {
        valid++;
      }


      found = 0;
      carry = 0;

    }

  printf("%d\n", valid);
  fclose(fp);

}
