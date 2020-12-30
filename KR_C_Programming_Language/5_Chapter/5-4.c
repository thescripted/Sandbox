#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main() {
    char *s = "Hello";
    char *t = "World";
    char *v = "llo";
    if (strend(s, v))
        printf("Found a comparision!\n");
    else
        printf("No match\n");
}

int strend(char *s, char *t) {
    int i, j;
    for (i = strlen(s), j = strlen(t); j >= 0  && *(s + i) == *(t + j); i--, j--)
        ;
    if (j < 0)
        return 1;
    return 0;
}
