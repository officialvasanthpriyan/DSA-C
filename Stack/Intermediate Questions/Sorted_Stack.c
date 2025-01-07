#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list implementation of stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* node = newNode(data);
    node->next = *top;
    *top = node;
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to peek at the top element of the stack
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Recursive function to insert an element in sorted order
void sortedInsert(Node** top, int element) {
    // Base case: stack is empty or the top element is smaller than the current element
    if (isEmpty(*top) || peek(*top) <= element) {
        push(top, element);
        return;
    }

    // Remove the top element and call sortedInsert recursively
    int temp = pop(top);
    sortedInsert(top, element);

    // Push the top element back onto the stack
    push(top, temp);
}

// Recursive function to sort the stack
void sortStack(Node** top) {
    // Base case: stack is empty
    if (isEmpty(*top)) {
        return;
    }

    // Remove the top element and sort the remaining stack
    int temp = pop(top);
    sortStack(top);

    // Insert the top element back in sorted order
    sortedInsert(top, temp);
}

// Function to print the stack
void printStack(Node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Main function to demonstrate sorting a stack
int main() {
    Node* stack = NULL;

    // Push elements onto the stack
    push(&stack, 30);
    push(&stack, -5);
    push(&stack, 18);
    push(&stack, 14);
    push(&stack, -3);

    printf("Original Stack:\n");
    printStack(stack);

    // Sort the stack
    sortStack(&stack);

    printf("Sorted Stack:\n");
    printStack(stack);

    return 0;
}
