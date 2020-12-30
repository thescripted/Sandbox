#include <stdio.h>
#define BUFSIZE 1000
static char line[BUFSIZE]; /* buffer for line */
static int bufp; /* position for buffer */
static int readflag = 1;
static int get_line(char *s, int max_length);

/* getch: reads a character */
int getch(void) {
    int length = 0;
    do {
        if (readflag == 1) {
            /* prime the line array */
            if ((length = get_line(line, BUFSIZE)) > 0) {
                if (length >= (BUFSIZE - 1)) {
                    printf("ERROR: line buffer exceeded.");
                    return EOF;
                }
            } else
                return EOF;
            bufp = 0;
            readflag = 0;
        }
        if (line[bufp] == '\0')
            readflag = 1; /* read a new line */
    } while (readflag);
    return line[bufp++];
}

/* ungetch: push character back on input */
void ungetch(void) {
    if (bufp > 0)
        --bufp;
}


/*
 * print_source: print out the contents of the line read.
 */
void print_source(void) {
    printf("%s", line);
}

/* 
 * get_line: 
 * This version will read a line up to a maximum number of characters
 * (max_length - 1) and store a '\0' at the end. The number of characters
 * read is returned, if that is a 0 then we're done reading lines.
 */
int get_line(char *s, int max_length) {
    int c;
    char *start = s; /* save pointer to start of buffer s */
    char *end = s + (max_length - 2); /* point near to end of buffer s */
    while ((c = getchar()) != EOF && c != '\n' && s < end)
        *s++ = c;
    if (c != EOF)
        *s++ = c; /* store last character read */
    *s = '\0'; /* terminate the line */
    return s - start; /* number of characters read */
}



