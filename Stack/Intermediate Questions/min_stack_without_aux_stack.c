// Implement a stack that can perform getMin() in O(1) without using an auxiliary stack.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
    int minElement;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->minElement = INT_MAX; // Initialize minElement
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push operation with min tracking
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }

    if (isEmpty(stack)) {
        stack->minElement = value;
        stack->arr[++stack->top] = value;
    } else {
        if (value < stack->minElement) {
            stack->arr[++stack->top] = 2 * value - stack->minElement;
            stack->minElement = value;
        } else {
            stack->arr[++stack->top] = value;
        }
    }

    printf("Pushed %d\n", value);
}

// Pop operation with min tracking
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }

    int topValue = stack->arr[stack->top--];

    if (topValue < stack->minElement) {
        int originalValue = stack->minElement;
        stack->minElement = 2 * stack->minElement - topValue;
        return originalValue;
    } else {
        return topValue;
    }
}

// Get minimum element
int getMin(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->minElement;
}

// Main function to demonstrate the stack operations
int main() {
    Stack* stack = createStack(10);

    push(stack, 5);
    push(stack, 3);
    printf("Current Min: %d\n", getMin(stack));
    push(stack, 7);
    printf("Current Min: %d\n", getMin(stack));
    push(stack, 2);
    printf("Current Min: %d\n", getMin(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Current Min: %d\n", getMin(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Current Min: %d\n", getMin(stack));

    return 0;
}
