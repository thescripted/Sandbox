#include <stdio.h>
#include <ctype.h>
#define ARRAY_SIZE 25

int getint(int *);
int main() {
    int n, arr[ARRAY_SIZE];
    for (n = 0; n < ARRAY_SIZE && getint(&arr[n]) != 0; n++)
        printf("%d\n", arr[n]);
}

int getch(void);
void ungetch(int);

int getint(int *ip) {
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if(!isdigit(c)) {
        ungetch(c);
        return 0;
    }
    for (*ip = 0; isdigit(c); c = getch())
        *ip = *ip * 10 + (c - '0');
    *ip *= sign;
    if (c == EOF)
        ungetch(c);
    return c;
}

#define MAX_BUFFER 100

int buf[MAX_BUFFER];
int bufp = 0;

int getch() {
    if (bufp > 0) {
        return buf[--bufp];
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (bufp >= MAX_BUFFER) {
        printf("Max buffer reached.\n");
    } else {
        buf[bufp++] = c;
    }
}
