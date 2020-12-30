#include <stdio.h>
#include <ctype.h>

char *geta(char **);
int main(int argc, char **argv) {
    // read inputs into routine
    // // routine is to run through each arg individually
    // // for each argument, if it's a number. push to a stack
    // // if it's a binary operator, pop two numbers from stack and eval, left to right. 
    //  -- note, second element popped will be the on the left-side of the operator
    //  -- put the result back into the stack.
    
    int left, right;
    char *c;
    void push(int);
    bool isoperator(char);

    while(--argc > 0 && (c = geta(argv)) != EOF) {
        if isdigit(c) {
            push(c - '0');
        } else if isoperator(c) {
            right = pop();
            left = pop();
            push(evaluate(left, right, c));
        }
    }
}

int i = 0;
char *geta(char **argv) {
    return *(argv + i++);
}

bool isoperator(char *op) {
    switch(*op) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
        default:
            return false;
    }
}
