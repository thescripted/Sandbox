#include <stdio.h>
#include <string.h>
#define MAXLINES 1000

char *lineptr[MAXLINES];
int readlines(char **, int);
void writelines(char **, int);
void qsort(char **, int, int);

int main() {
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES) >= 0)) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    return 0;
}


