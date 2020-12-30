#include <stdio.h>
#include <ctype.h>
#define ARRAY_SIZE 25

int getfloat(double *);
int main() {
    int n;
    double arr[ARRAY_SIZE];
    for (n = 0; n < ARRAY_SIZE && getfloat(&arr[n]) != 0; n++)
        printf("%.3f\n", arr[n]);
}

int getch(void);
void ungetch(int);

int getfloat(double *ip) {
    int c, sign;
    unsigned long power;
    unsigned long tmp;
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
    for (tmp = 0; isdigit(c); c = getch())
        tmp = tmp * 10 + (c - '0');
    if (c == '.') {
        c = getch();
        for (power = 1; isdigit(c); c = getch()) {
            power *= 10;
            tmp = tmp * 10 + (c - '0');
        }
        *ip = (double)tmp / power;
    } else {
        *ip = tmp;
    }
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
