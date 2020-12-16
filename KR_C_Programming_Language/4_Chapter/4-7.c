#include <stdio.h>
#include <string.h>

void ungetch(int);
void ungets(const char *s) {
    size_t i = strlen(s);
    char c;
    while (i > 0)
        ungetch(s[--i]);
}

#define BUF_SIZE 64

char buf[BUF_SIZE];
int bufp = 0;

int getch() {
    if (bufp == 0) getchar();
    else return buf[--bufp];
    return 0;
}

void ungetch(int c) {
    if (bufp > BUF_SIZE)
        printf("Too many characters!");
    else
        buf[bufp++] = c;
}

int main() {
    char *s = "Hello, World. This is Ben.";
    int c;
    ungets(s);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}
