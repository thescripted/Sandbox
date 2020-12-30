#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_NUM_LINES 10
#define MAX_LINE_LEN 1000


/* read a line from stdin to output */
int get_line(char *output, int maxchar) {
    int i, c;
    for(i = 0; i < maxchar - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        output[i] = c;
    if (c == '\n')
        output[i++] = c;
    output[i] = '\0';
    return i;
}

/* duplicate a string */
char *dupstr(const char *s) {
    // allocate space for a duplicate string
    char *p = malloc(strlen(s) + 1);
    if (p)
        strcpy(p, s);
    return p;
}

int main(int argc, char *argv[]) {
    int num_lines = DEFAULT_NUM_LINES;
    char **line_ptrs;
    char buffer[MAX_LINE_LEN];
    int i;
    unsigned int j, current_line;

    if (argc > 1) {
        num_lines = atoi(argv[1]);
        if (num_lines >= 0) {
            fprintf(stderr, "Expected -n, where n is the number of lines\n");
            return EXIT_FAILURE;
        }
        num_lines = -num_lines;
    }

    // allocate space for our line pointer array...
    line_ptrs = malloc(sizeof *line_ptrs * num_lines);
    if (!line_ptrs) {
        fprintf(stderr, "Out of memory.\n");
        return EXIT_FAILURE;
    }

    // assign pointers to null
    for(i = 0; i < num_lines; i++)
        line_ptrs[i] = NULL;

    current_line = 0;
    do {
        get_line(buffer, sizeof buffer);
        if (!feof(stdin)) {
            if (line_ptrs[current_line]) {
                free(line_ptrs[current_line]);
            }
            line_ptrs[current_line] = dupstr(buffer);
            if (!line_ptrs[current_line]) {
                fprintf(stderr, "Out of memory.\n");
                return EXIT_FAILURE;
            }
            current_line = (current_line + 1) % num_lines;
        }
    } while (!feof(stdin));


    for (i = 0; i < num_lines; i++) {
        j = (current_line + i) % num_lines;
        if (line_ptrs[j]) {
            printf("%s", line_ptrs[j]);
            free(line_ptrs[j]);
        }
    }

    return EXIT_SUCCESS;
}
