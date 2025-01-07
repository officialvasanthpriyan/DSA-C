<<<<<<< HEAD
// Find the smallest number following a given pattern of 'I' (increase) and 'D' (decrease) using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the smallest number following the pattern
void findSmallestNumber(char* pattern) {
    int n = strlen(pattern);  // Length of the pattern
    int* stack = (int*)malloc((n + 1) * sizeof(int));  // Stack to store numbers
    int top = -1;  // Top of the stack
    int num = 1;   // Start with the smallest number

    printf("Smallest number following the pattern is: ");

    // Iterate over the pattern
    for (int i = 0; i <= n; i++) {
        // Push the current number onto the stack
        stack[++top] = num++;

        // If the pattern is 'I' or it's the last character
        if (i == n || pattern[i] == 'I') {
            // Pop and print all elements from the stack
            while (top != -1) {
                printf("%d", stack[top--]);
            }
        }
    }

    // Free the allocated memory
    free(stack);
    printf("\n");
}

int main() {
    char pattern[100];

    // Input the pattern
    printf("Enter the pattern (only 'I' and 'D'): ");
    scanf("%s", pattern);

    // Validate the pattern
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != 'I' && pattern[i] != 'D') {
            printf("Invalid pattern! Please use only 'I' and 'D'.\n");
            return 1;
        }
    }

    // Call the function to find the smallest number
    findSmallestNumber(pattern);

    return 0;
}
=======
// Find the smallest number following a given pattern of 'I' (increase) and 'D' (decrease) using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the smallest number following the pattern
void findSmallestNumber(char* pattern) {
    int n = strlen(pattern);  // Length of the pattern
    int* stack = (int*)malloc((n + 1) * sizeof(int));  // Stack to store numbers
    int top = -1;  // Top of the stack
    int num = 1;   // Start with the smallest number

    printf("Smallest number following the pattern is: ");

    // Iterate over the pattern
    for (int i = 0; i <= n; i++) {
        // Push the current number onto the stack
        stack[++top] = num++;

        // If the pattern is 'I' or it's the last character
        if (i == n || pattern[i] == 'I') {
            // Pop and print all elements from the stack
            while (top != -1) {
                printf("%d", stack[top--]);
            }
        }
    }

    // Free the allocated memory
    free(stack);
    printf("\n");
}

int main() {
    char pattern[100];

    // Input the pattern
    printf("Enter the pattern (only 'I' and 'D'): ");
    scanf("%s", pattern);

    // Validate the pattern
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != 'I' && pattern[i] != 'D') {
            printf("Invalid pattern! Please use only 'I' and 'D'.\n");
            return 1;
        }
    }

    // Call the function to find the smallest number
    findSmallestNumber(pattern);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
