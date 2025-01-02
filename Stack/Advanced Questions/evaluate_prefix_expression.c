// Evaluate an expression given in prefix notation using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include  <string.h>

// Function to perform arithmetic operations
int applyOperator(char op, int operand1, int operand2) {
    switch(op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* expression) {
    int stack[100]; // Stack to store operands
    int top = -1; // Stack pointer

    // Traverse the expression from right to left
    for(int i = strlen(expression) - 1; i >= 0; i--) {
        char ch = expression[i];

        // If character is a digit, push it to the stack
        if (isdigit(ch)) {
            stack[++top] = ch - '0'; // Convert char to int
        } else if (ch == ' ' || ch == '\t') {
            continue; // Skip spaces
        } else {
            // Pop two operands from the stack and apply the operator
            int operand1 = stack[top--];
            int operand2 = stack[top--];
            int result = applyOperator(ch, operand1, operand2);
            stack[++top] = result; // Push the result back to the stack
        }
    }

    // The final result is at the top of the stack
    return stack[top];
}

// Main function
int main() {
    char expression[100];

    printf("Enter the prefix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Evaluate the prefix expression
    int result = evaluatePrefix(expression);

    printf("The result of the prefix expression is: %d\n", result);
    return 0;
}
