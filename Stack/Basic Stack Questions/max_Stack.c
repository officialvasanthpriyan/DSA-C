// Implement a stack that supports push, pop, and retrieving the maximum element in constant time.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for Max Stack
typedef struct {
    int mainStack[MAX];  // Main stack to store all elements
    int maxStack[MAX];   // Auxiliary stack to store maximum values
    int topMain;         // Top pointer for the main stack
    int topMax;          // Top pointer for the max stack
} MaxStack;

// Initialize the Max Stack
void initMaxStack(MaxStack *stack) {
    stack->topMain = -1;
    stack->topMax = -1;
}

// Check if the stack is full
int isFull(MaxStack *stack) {
    return stack->topMain == MAX - 1;
}

// Check if the stack is empty
int isEmpty(MaxStack *stack) {
    return stack->topMain == -1;
}

// Push an element onto the stack
void push(MaxStack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }

    // Push the value onto the main stack
    stack->mainStack[++(stack->topMain)] = value;

    // Push the value onto the max stack if it is greater than or equal to the current max
    if (stack->topMax == -1 || value >= stack->maxStack[stack->topMax]) {
        stack->maxStack[++(stack->topMax)] = value;
    }
}

// Pop an element from the stack
void pop(MaxStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return;
    }

    // If the popped element is the same as the top of the max stack, pop from the max stack as well
    if (stack->mainStack[stack->topMain] == stack->maxStack[stack->topMax]) {
        stack->topMax--;
    }

    // Pop from the main stack
    stack->topMain--;
}

// Get the top element of the stack
int top(MaxStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return stack->mainStack[stack->topMain];
}

// Get the maximum element in the stack
int getMax(MaxStack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! No maximum element.\n");
        return INT_MIN;
    }
    return stack->maxStack[stack->topMax];
}

// Main function to demonstrate the Max Stack
int main() {
    MaxStack stack;
    initMaxStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 5);
    push(&stack, 15);

    printf("Top element: %d\n", top(&stack));
    printf("Maximum element: %d\n", getMax(&stack));

    pop(&stack);
    printf("After popping, top element: %d\n", top(&stack));
    printf("After popping, maximum element: %d\n", getMax(&stack));

    return 0;
}
