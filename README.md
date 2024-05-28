# Reverse-Polish-Calculator

## Overview

The RPN (Reverse Polish Notation) calculator is a program that evaluates mathematical expressions written in postfix notation. In postfix notation, operators follow their operands, which eliminates the need for parentheses to define the order of operations.

## Features

- Supports basic arithmetic operations: addition, multiplication, and division.
- Handles integer inputs and operations.
- Provides error handling for invalid input.

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
3. [Code Explanation](#code-explanation)
4. [Contribution Guidelines](#contribution-guidelines)
5. [Testing](#testing)
6. [Troubleshooting](#troubleshooting)
7. [Future Enhancements](#future-enhancements)

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/rpn-calculator.git
   cd rpn-calculator
2. **Build the project:**
   ```bash
   make
3. **Run the program:**
   ```bash
   ./rpn_calculator
   
## Usage

To use the RPN calculator, run the program and enter a postfix expression.

1. **For example:**
   ```bash
   > 3 4 + 2 *
    14

## Code Explanation

### Main Loop

The main loop processes the input character by character and updates the program's state accordingly:
1. **Main Loop:**
   ```bash
   while (state != ERROR && ((c = getchar()) != EOF)) {
    switch (state) {
        // State transitions and actions
      }
   }
## State Machine
Manages the different states of input processing:

**START:** Initial state.
**NUMBER:** Reading a number.
**SPACE:** Handling spaces.
**OPERATOR:** Handling an operator.
**ERROR:** Error state.
**NEWLINE:** End of the line or expression.

## Stack Operations
Used to store numbers and intermediate results:
1. **C**
   ```bash
   int stack[MAXLEN], stackpos = 0;

    void push(int number) {
        stack[stackpos++] = number;
    }
    
    int pop() {
        return stack[--stackpos];
    }

## Operation Functions
Defines basic arithmetic operations:
1. **C**
   ```bash
   int add(int a, int b) { return a + b; }
   int mul(int a, int b) { return a * b; }
   int div(int a, int b) { return a / b; }

## Contribution Guidelines

1. **Branching:**
- Create a new branch for each feature or bug fix.
- Branch naming convention: feature/feature-name or bugfix/bug-description.
  

2. **Commits:**
- Write clear and concise commit messages.
- Commit frequently to document progress.
  
 
3. **Pull Requests:**
- Ensure your branch is up-to-date with the main branch before creating a pull request.
- Include a detailed description of the changes.
- Request reviews from team members.
  
  
## Testing
To ensure correctness, test cases are provided in the tests/test_cases.c file.

1. **Run the tests:**
   ```bash
   int add(int a, int b) { return a + b; }
   int mul(int a, int b) { return a * b; }
   int div(int a, int b) { return a / b; }

## Troubleshooting

**Common Issues:**

- Ensure you have the necessary build tools installed (gcc, make).
- Check for syntax errors and unresolved references.
- Refer to error messages for clues about the issue.
  
**Debugging:**

- Use printf statements to print variable values and program flow.
- Consider using a debugger like gdb for more in-depth analysis.
  
## Future Enhancements

- Additional Operations: Implement more arithmetic operations such as exponentiation and modulus.
- Enhanced Error Handling: Improve error messages to provide more context.
- User Interface: Develop a graphical user interface for easier interaction.

