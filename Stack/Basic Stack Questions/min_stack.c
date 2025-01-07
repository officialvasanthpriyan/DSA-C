// Implement a min stack that supports push, pop, and retrieving the minimum element in constant time.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for Min Stack
typedef struct {
    int mainStack[MAX]; // Main stack to store all elements
    int minStack[MAX];  // Auxiliary stack to store minimum values
    int topMain;        // Top pointer for the main stack
    int topMin;         // Top pointer for the min stack
} MinStack;

// Initialize the Min Stack
void initMinStack(MinStack *stack) {
    stack->topMain = -1;
    stack->topMin = -1;
}

// Check if the stack is full
int isFull(MinStack *stack) {
    return stack->topMain == MAX - 1;
}

// Check if the stack is empty
int isEmpty(MinStack *stack) {
    return stack->topMain == -1;
}

// Push an element onto the stack
void push(MinStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }

    // Push onto the main stack
    stack->mainStack[++(stack->topMain)] = value;

    // Push onto the min stack
    if (stack->topMin == -1 || value <= stack->minStack[stack->topMin]) {
        stack->minStack[++(stack->topMin)] = value;
    }
}

// Pop an element from the stack
void pop(MinStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return;
    }

    // Pop from the min stack if the top of the main stack matches
    if (stack->mainStack[stack->topMain] == stack->minStack[stack->topMin]) {
        (stack->topMin)--;
    }

    // Pop from the main stack
    (stack->topMain)--;
}

// Get the top element of the stack
int top(MinStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return stack->mainStack[stack->topMain];
}

// Get the minimum element in the stack
int getMin(MinStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No minimum element.\n");
        return INT_MIN;
    }
    return stack->minStack[stack->topMin];
}

// Main function to demonstrate the Min Stack
int main() {
    MinStack stack;
    initMinStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 5);
    push(&stack, 15);

    printf("Top element: %d\n", top(&stack));
    printf("Minimum element: %d\n", getMin(&stack));

    pop(&stack);
    printf("After popping, top element: %d\n", top(&stack));
    printf("After popping, minimum element: %d\n", getMin(&stack));

    return 0;
}
