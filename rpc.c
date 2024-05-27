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
    
}
