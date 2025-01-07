// Simulate a browser's forward and backward navigation using two stacks.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define URL_LENGTH 100

// Define a stack structure
typedef struct {
    int top;
    char items[MAX][URL_LENGTH];
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
void push(Stack* stack, char* value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    strcpy(stack->items[++stack->top], value);
}

// Pop an element from the stack
char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->items[stack->top--];
}

// Peek at the top element of the stack
char* peek(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->items[stack->top];
}

// Simulate browser navigation
void simulateBrowserNavigation() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);

    char currentURL[URL_LENGTH] = "homepage.com";  // Start with the homepage
    int choice;

    do {
        printf("\nCurrent Page: %s\n", currentURL);
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char newURL[URL_LENGTH];

        switch (choice) {
            case 1:
                // Visit a new page
                printf("Enter new URL: ");
                scanf("%s", newURL);

                push(&backStack, currentURL);  // Push current page onto back stack
                strcpy(currentURL, newURL);   // Update current URL
                while (!isEmpty(&forwardStack)) {
                    pop(&forwardStack);       // Clear forward stack
                }
                break;

            case 2:
                // Back navigation
                if (!isEmpty(&backStack)) {
                    push(&forwardStack, currentURL);  // Push current page onto forward stack
                    strcpy(currentURL, pop(&backStack));  // Pop the back stack for the new current page
                } else {
                    printf("No pages in the back history!\n");
                }
                break;

            case 3:
                // Forward navigation
                if (!isEmpty(&forwardStack)) {
                    push(&backStack, currentURL);  // Push current page onto back stack
                    strcpy(currentURL, pop(&forwardStack));  // Pop the forward stack for the new current page
                } else {
                    printf("No pages in the forward history!\n");
                }
                break;

            case 4:
                printf("Exiting browser simulation.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    simulateBrowserNavigation();
    return 0;
}
