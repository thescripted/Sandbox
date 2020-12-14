#include <stdio.h>
#include <string.h>


void reverse(char *msg) {
    int c, i, j;
    for (i = 0, j = strlen(msg) - 1; i < j; i++, j--) {
        c = msg[i];
        msg[i] = msg[j];
        msg[j] = c;
    }
}

void itob(int n, char *s, short b) {
    int i = 0;
    char c;
    do {
        c = n % b;
        s[i++] = c + '0';
    } while((n /= b) > 0);
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = 28;
    int base = 2;
    char s[24];
    itob(n, s, base);
    printf("%d has converted into %s\n", n, s);
    return 0;
}
