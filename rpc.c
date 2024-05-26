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
int main() {
    //code
}
