#include <stdio.h>
#include <string.h>

void ungetch(int);
void ungets(const char *s) {
    size_t i = strlen(s);
    while (i > 0)
        ungetch(s[--i]);
}

#define BUF_SIZE 64

// Buffer cannot support EOF. So it shouldn't be allowed.
char buf[BUF_SIZE];
int bufp = 0;

int getch() {
    if (bufp == 0) getchar();
    else return buf[--bufp];
    return 0;
}

// Calling routines can provide EOF, but it will get ignored here.
void ungetch(int c) {
    if (bufp > BUF_SIZE)
        printf("Too many characters!");
    else if (c != EOF)
        buf[bufp++] = c;
}

int main() {
    char *s = "Hello, World. This is Ben.";
    int c;
    ungets(s);
    ungetch(EOF); // Premature EOF)
    while ((c = getch()) != EOF) // Here, EOF can be supplied through getchar(), but never from buffer.
        putchar(c);
    return 0;
}
