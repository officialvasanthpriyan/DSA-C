// Find the next greater element for each element in an array using a stack.

#include <stdio.h>
#include <stdlib.h>

// Function to find the next greater element for each element in the array
void nextGreaterElement(int arr[], int n) {
    int *result = (int *)malloc(n * sizeof(int)); // To store results
    int *stack = (int *)malloc(n * sizeof(int)); // Stack to store indices
    int top = -1; // Stack top pointer

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack smaller than or equal to the current element
        while (top != -1 && stack[top] <= arr[i]) {
            top--;
        }

        // If the stack is empty, no greater element exists
        if (top == -1) {
            result[i] = -1;
        } else {
            // The top of the stack is the next greater element
            result[i] = stack[top];
        }

        // Push the current element onto the stack
        stack[++top] = arr[i];
    }

    // Print the results
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }

    // Free allocated memory
    free(result);
    free(stack);
}

// Main function
int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}
