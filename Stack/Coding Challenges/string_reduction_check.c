// Check if a given string can be reduced to an empty string using stack-based operations.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Define a stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Peek at the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top];
}

// Check if the string can be reduced to an empty string
int canReduceToEmptyString(char* str) {
    Stack stack;
    initStack(&stack);

    // Iterate through the string
    for (int i = 0; str[i] != '\0'; i++) {
        // If the stack is not empty and the top character matches the current one, pop it
        if (!isEmpty(&stack) && peek(&stack) == str[i]) {
            pop(&stack);
        } else {
            // Otherwise, push the current character onto the stack
            push(&stack, str[i]);
        }
    }

    // If the stack is empty, the string can be reduced to an empty string
    return isEmpty(&stack);
}

int main() {
    char str[MAX];

    // Input the string
    printf("Enter the string: ");
    scanf("%s", str);

    // Check if the string can be reduced
    if (canReduceToEmptyString(str)) {
        printf("The string can be reduced to an empty string.\n");
    } else {
        printf("The string cannot be reduced to an empty string.\n");
    }

    return 0;
}
