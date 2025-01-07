// Generate all possible valid parentheses for a given number of pairs using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the stack
typedef struct {
    char* arr;  // Array to store parentheses
    int top;    // Index of the top element in the stack
    int size;   // Maximum size of the stack
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (char*)malloc(size * sizeof(char));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, char ch) {
    if (stack->top == stack->size - 1) {
        return;  // Stack overflow (should not occur in this scenario)
    }
    stack->arr[++stack->top] = ch;
}

// Pop an element from the stack
char pop(Stack* stack) {
    if (stack->top == -1) {
        return '\0';  // Stack underflow
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Generate valid parentheses recursively
void generateParentheses(int open, int close, Stack* stack, int index) {
    // If all parentheses are used, print the combination
    if (open == 0 && close == 0) {
        stack->arr[index] = '\0';  // Null-terminate the string
        printf("%s\n", stack->arr);
        return;
    }

    // Add an open parenthesis if available
    if (open > 0) {
        stack->arr[index] = '(';
        generateParentheses(open - 1, close, stack, index + 1);
    }

    // Add a close parenthesis if it will not make the combination invalid
    if (close > open) {
        stack->arr[index] = ')';
        generateParentheses(open, close - 1, stack, index + 1);
    }
}

int main() {
    int n;

    // Input the number of pairs of parentheses
    printf("Enter the number of pairs of parentheses: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Number of pairs should be greater than 0.\n");
        return 1;
    }

    // Create a stack to store the parentheses
    Stack* stack = createStack(2 * n);

    // Generate and print all valid parentheses
    printf("All possible valid parentheses combinations are:\n");
    generateParentheses(n, n, stack, 0);

    // Free the allocated memory
    free(stack->arr);
    free(stack);

    return 0;
}

