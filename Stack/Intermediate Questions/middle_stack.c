// Design a stack that supports middle element retrieval and deletion in constant time
#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Stack structure
typedef struct Stack {
    Node* head;    // Top of the stack
    Node* mid;     // Pointer to the middle element
    int size;      // Size of the stack
} Stack;

// Function to create a new node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to initialize the stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->mid = NULL;
    stack->size = 0;
    return stack;
}

// Push operation
void push(Stack* stack, int data) {
    Node* node = createNode(data);
    node->next = stack->head;

    if (stack->head != NULL) {
        stack->head->prev = node;
    }
    stack->head = node;

    stack->size++;
    if (stack->size == 1) {
        stack->mid = node; // Set mid to the first node
    } else if (stack->size % 2 == 0) {
        stack->mid = stack->mid->prev; // Move mid back for even size
    }

    printf("%d pushed to stack\n", data);
}

// Pop operation
int pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack underflow!\n");
        return -1;
    }

    Node* temp = stack->head;
    int data = temp->data;

    stack->head = temp->next;
    if (stack->head != NULL) {
        stack->head->prev = NULL;
    }

    stack->size--;
    if (stack->size % 2 == 1) {
        stack->mid = stack->mid->next; // Move mid forward for odd size
    }

    free(temp);
    return data;
}

// Get middle element
int getMiddle(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->mid->data;
}

// Delete middle element
void deleteMiddle(Stack* stack) {
    if (stack->size == 0) {
        printf("Stack is empty!\n");
        return;
    }

    Node* temp = stack->mid;

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (stack->size % 2 == 0) {
        stack->mid = temp->next; // Move mid forward for even size
    } else {
        stack->mid = temp->prev; // Move mid backward for odd size
    }

    stack->size--;
    free(temp);
    printf("Middle element deleted.\n");
}

// Main function to demonstrate the stack operations
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    printf("Middle element: %d\n", getMiddle(stack));
    deleteMiddle(stack);
    printf("Middle element after deletion: %d\n", getMiddle(stack));

    printf("Popped: %d\n", pop(stack));
    printf("Middle element: %d\n", getMiddle(stack));

    return 0;
}
