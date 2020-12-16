#include <stdio.h>

void push(double);
double pop(void);
double peek(void);
int main() {
    double currval;
    push(3.0);
    printf("pushed: %g\n", 3.0);
    push(1.4);
    printf("pushed: %g\n", 1.4);
    push(6.4);
    printf("pushed: %g\n", 6.4);
    currval = pop();
    printf("pop: %g\n", currval);
    currval = peek();
    printf("peek: %g\n", currval);
    currval = peek();
    printf("peek: %g\n", currval);
    currval = pop();
    printf("pop: %g\n", currval);
    currval = peek();
    printf("peek: %g\n", currval);
    return 0;
}


#define MAX_VAL 100

int sp = 0;
double val[MAX_VAL];
void push(double f) {
    if (sp < MAX_VAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack empty");
        return 0.0;
    }
}

double peek() {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("stack empty");
        return 0.0;
    }
}
