#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 1000

// Function pointer type for operations
typedef int(*opfunc)(int, int);

// Enumeration for state machine
typedef enum {
    START,     // Initial state
    NUMBER,    // Reading a number
    SPACE,     // Handling spaces
    MINUS,     // Handling minus sign
    NEWLINE,   // End of line
    OPERATOR,  // Handling operator
    ERROR      // Error state
} State;

// Functions for operations
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

// Function to get the appropriate operation function based on the character
opfunc getop(char c) {
    switch (c) {
        case '+':
            return add;
        case '*':
            return mul;
        case '/':
            return div;
        default:
            return NULL;
    }
}

int main() {
    State state = START; // Initialize state to START
    int c, number, stack[MAXLEN], sign = 1, stackpos = 0;
    char message[MAXLEN];
    opfunc op = NULL; // Operation function pointer

    // Main input processing loop
    printf("Enter an Expression : ");
    while (state != ERROR && ((c = getchar()) != EOF)) {
        if (state == START) {
            if (isdigit(c)) {
                number = c - '0';
                state = NUMBER;
            } else if (c == '\n') {
                continue; // Ignore newlines in START state
            } else if (isspace(c)) {
                state = SPACE;
            } else if (c == '-') {
                state = MINUS;
            } else {
                state = ERROR;
                strcpy(message, "Invalid character at start of line");
            }
        } else if (state == NUMBER) {
            if (isdigit(c)) {
                number = (number * 10) + (c - '0');
            } else if (c == '\n') {
                stack[stackpos++] = sign * number;
                sign = 1;
                state = NEWLINE;
            } else if (isspace(c)) {
                stack[stackpos++] = sign * number;
                sign = 1;
                state = SPACE;
            } else {
                state = ERROR;
                strcpy(message, "Invalid character at the end of number");
            }
        } else if (state == MINUS) {
            if (isdigit(c)) {
                number = c - '0';
                sign = -1;
                state = NUMBER;
                continue;
            }
            if (stackpos < 2) {
                state = ERROR;
                strcpy(message, "More operands required");
            } else if (isspace(c)) {
                int right = stack[--stackpos];
                int left = stack[--stackpos];
                stack[stackpos++] = left - right;
                state = c == '\n' ? NEWLINE : SPACE;
            } else {
                state = ERROR;
                strcpy(message, "Invalid character after '-'");
            }
        } else if (state == SPACE) {
            if (isdigit(c)) {
                number = c - '0';
                state = NUMBER;
            } else if (c == '\n') {
                state = NEWLINE;
            } else if (c == '-') {
                state = MINUS;
            } else if (!isspace(c)) {
                op = getop(c);
                if (op == NULL) {
                    state = ERROR;
                    strcpy(message, "Expected one of +/*");
                } else {
                    if (stackpos < 2) {
                        state = ERROR;
                        strcpy(message, "More operands required");
                        continue;
                    }
                    int right = stack[--stackpos];
                    int left = stack[--stackpos];
                    if (right == 0 && c == '/') {
                        state = ERROR;
                        strcpy(message, "Division by zero");
                    } else {
                        stack[stackpos++] = op(left, right);
                        state = OPERATOR;
                    }
                }
            }
            
        } else if (state == OPERATOR) {
            if (c == '\n') {
                state = NEWLINE;
            } else if (isspace(c)) {
                state = SPACE;
            } else {
                strcpy(message, "Expected space or newline after operator");
                state = ERROR;
            }
        }

        if (state == NEWLINE) {
            if (stackpos > 1) {
                state = ERROR;
                strcpy(message, "Too many operands");
            } else {
                if (stackpos == 1) {
                    printf("Result: %d\n", stack[0]);
                    stackpos = 0;
                }
                state = START;
            }
        }
    }

    if (state == ERROR) {
        printf("%s\n", message);
    } else if (stackpos > 1) {
        printf("Too many operands\n");
    } else if (stackpos == 1) {
        printf("Result: %d\n", stack[0]);
    }
    return 0;
}
