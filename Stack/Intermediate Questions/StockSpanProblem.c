<<<<<<< HEAD
// Find the span of stock prices for n days using a stack (Stock Span Problem).
#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int prices[], int n, int span[]) {
    // Create a stack to store indices
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1; // Initialize stack as empty

    // Process each stock price
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while stack is not empty
        // and the price at the top of the stack is less than or equal to the current price
        while (top != -1 && prices[stack[top]] <= prices[i]) {
            top--;
        }

        // Calculate the span
        if (top == -1) {
            span[i] = i + 1; // Current price is the highest so far
        } else {
            span[i] = i - stack[top];
        }

        // Push the current index onto the stack
        stack[++top] = i;
    }

    free(stack); // Free allocated memory
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateSpan(prices, n, span);

    printf("Stock Prices: ");
    printArray(prices, n);

    printf("Span:         ");
    printArray(span, n);

    return 0;
}

=======
// Find the span of stock prices for n days using a stack (Stock Span Problem).
#include <stdio.h>
#include <stdlib.h>

void calculateSpan(int prices[], int n, int span[]) {
    // Create a stack to store indices
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1; // Initialize stack as empty

    // Process each stock price
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while stack is not empty
        // and the price at the top of the stack is less than or equal to the current price
        while (top != -1 && prices[stack[top]] <= prices[i]) {
            top--;
        }

        // Calculate the span
        if (top == -1) {
            span[i] = i + 1; // Current price is the highest so far
        } else {
            span[i] = i - stack[top];
        }

        // Push the current index onto the stack
        stack[++top] = i;
    }

    free(stack); // Free allocated memory
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateSpan(prices, n, span);

    printf("Stock Prices: ");
    printArray(prices, n);

    printf("Span:         ");
    printArray(span, n);

    return 0;
}

>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
