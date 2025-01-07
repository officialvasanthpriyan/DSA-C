// Implement a queue using two stacks.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int top;
} Stack;

// Function prototypes
void push(Stack* stack, int value);
int pop(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void enqueue(Stack* stack1, int value);
int dequeue(Stack* stack1, Stack* stack2);
void display(Stack* stack1, Stack* stack2);
void transfer(Stack* source, Stack* destination);

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;  // Return -1 to indicate an error
    }
    return stack->data[stack->top--];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Check if the stack is full
int isFull(Stack* stack) {
    return (stack->top == SIZE - 1);
}

// Enqueue operation: Add an element to the queue
void enqueue(Stack* stack1, int value) {
    push(stack1, value);
    printf("Enqueued: %d\n", value);
}

// Dequeue operation: Remove an element from the queue
int dequeue(Stack* stack1, Stack* stack2) {
    if (isEmpty(stack2)) {
        if (isEmpty(stack1)) {
            printf("Queue is empty. Cannot dequeue.\n");
            return -1;  // Return -1 to indicate an error
        }
        // Transfer elements from stack1 to stack2
        transfer(stack1, stack2);
    }
    return pop(stack2);
}

// Transfer elements from one stack to another
void transfer(Stack* source, Stack* destination) {
    while (!isEmpty(source)) {
        push(destination, pop(source));
    }
}

// Display the elements in the queue
void display(Stack* stack1, Stack* stack2) {
    Stack temp1 = *stack1;  // Temporary copy of stack1
    Stack temp2 = *stack2;  // Temporary copy of stack2

    printf("Queue elements: ");
    // Display stack2 in reverse order (top to bottom)
    while (!isEmpty(&temp2)) {
        printf("%d ", pop(&temp2));
    }

    // Transfer elements from stack1 to stack2 for reverse display
    transfer(&temp1, &temp2);

    // Display stack1 (original order)
    while (!isEmpty(&temp2)) {
        printf("%d ", pop(&temp2));
    }
    printf("\n");
}

int main() {
    Stack stack1 = {.top = -1};  // Stack for enqueue operations
    Stack stack2 = {.top = -1};  // Stack for dequeue operations

    int choice, value;

    while (1) {
        printf("\nQueue Operations Using Two Stacks:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Validate user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                enqueue(&stack1, value);
                break;
            case 2:
                value = dequeue(&stack1, &stack2);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&stack1, &stack2);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
