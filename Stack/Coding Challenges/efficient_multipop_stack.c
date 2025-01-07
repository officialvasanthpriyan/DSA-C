// Implement a stack with an efficient multi-pop operation.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop a single element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Multi-pop operation: Pop `count` elements from the stack
void multiPop(Stack* stack, int count) {
    printf("Multi-popping %d elements:\n", count);

    while (count > 0 && !isEmpty(stack)) {
        printf("%d ", pop(stack));
        count--;
    }

    if (count > 0) {
        printf("\nStack underflow! Could not pop all requested elements.\n");
    } else {
        printf("\nMulti-pop operation completed.\n");
    }
}

// Display the stack contents
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents (top to bottom): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    int choice, value, count;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Multi-pop\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter the number of elements to multi-pop: ");
                scanf("%d", &count);
                multiPop(&stack, count);
                break;

            case 4:
                display(&stack);
                break;

            case 5:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
