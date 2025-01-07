#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the smallest string following the given pattern
void findSmallestString(const char* pattern) {
    int n = strlen(pattern) + 1; // Length of the result string
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1; // Initialize stack top

    // Variable to track the current number to be pushed
    int num = 1;

    printf("Smallest string: ");

    // Traverse the pattern
    for (int i = 0; i <= strlen(pattern); i++) {
        // Push the current number onto the stack
        stack[++top] = num++;

        // If the current pattern character is 'I' or end of pattern
        if (i == strlen(pattern) || pattern[i] == 'I') {
            // Pop all elements from the stack and print
            while (top != -1) {
                printf("%d", stack[top--]);
            }
        }
    }

    printf("\n");

    free(stack); // Free allocated memory
}

int main() {
    char pattern[100];

    // Input the pattern
    printf("Enter the pattern (I for increase, D for decrease): ");
    scanf("%s", pattern);

    // Validate the pattern
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != 'I' && pattern[i] != 'D') {
            printf("Invalid pattern! Only 'I' and 'D' are allowed.\n");
            return 1;
        }
    }

    // Call the function to find the smallest string
    findSmallestString(pattern);

    return 0;
}
