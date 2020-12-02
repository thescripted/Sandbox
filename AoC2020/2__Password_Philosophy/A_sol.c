#include <stdio.h>
#include <ctype.h>

int main() {
  FILE *fp = fopen("input.txt", "r");
  char *search, line[100];
  char *current;
  int start, end, counter;
  int carry = 0;
  int valid = 0;
  
    while (fgets(line, 100, fp) != NULL) {
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
      current = &line[7 + carry];


      while (*current != '\0') {
        if (*current == *search) {
          counter++;
        }
        current++;
      }

      if (counter >= start && counter <= end) {
        valid++;
      }
      carry = 0;

    }
  printf("%d\n", valid);
  fclose(fp);

}
