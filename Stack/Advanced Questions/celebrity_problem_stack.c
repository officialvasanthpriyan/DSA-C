<<<<<<< HEAD
// Solve the Celebrity Problem using stacks.
#include <stdio.h>
#include <stdlib.h>

// Function to check if person i knows person j
int knows(int i, int j) {
    // The matrix or array representing the relationships should be defined here
    // For simplicity, returning 0/1 based on a mock relationship matrix
    // Example: 1 means knows, 0 means doesn't know
    int relationship[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0}
    };
    return relationship[i][j];
}

// Function to find the celebrity
int findCelebrity(int n) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Find the potential celebrity
    while (top > 0) {
        int person1 = stack[top--];
        int person2 = stack[top];

        // If person1 knows person2, person1 can't be a celebrity, push person2 back
        if (knows(person1, person2)) {
            stack[top] = person2;
        }
        // If person1 doesn't know person2, person2 can't be a celebrity, push person1 back
        else {
            stack[top] = person1;
        }
    }

    // The candidate celebrity
    int candidate = stack[0];

    // Verify if the candidate is truly a celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate should not know anyone, and everyone should know the candidate
            if (knows(candidate, i) || !knows(i, candidate)) {
                free(stack);
                return -1; // No celebrity
            }
        }
    }

    free(stack);
    return candidate;
}

// Main function
int main() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    int celebrity = findCelebrity(n);
    if (celebrity == -1) {
        printf("No celebrity found\n");
    } else {
        printf("The celebrity is person %d\n", celebrity);
    }

    return 0;
}
=======
// Solve the Celebrity Problem using stacks.
#include <stdio.h>
#include <stdlib.h>

// Function to check if person i knows person j
int knows(int i, int j) {
    // The matrix or array representing the relationships should be defined here
    // For simplicity, returning 0/1 based on a mock relationship matrix
    // Example: 1 means knows, 0 means doesn't know
    int relationship[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0}
    };
    return relationship[i][j];
}

// Function to find the celebrity
int findCelebrity(int n) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Find the potential celebrity
    while (top > 0) {
        int person1 = stack[top--];
        int person2 = stack[top];

        // If person1 knows person2, person1 can't be a celebrity, push person2 back
        if (knows(person1, person2)) {
            stack[top] = person2;
        }
        // If person1 doesn't know person2, person2 can't be a celebrity, push person1 back
        else {
            stack[top] = person1;
        }
    }

    // The candidate celebrity
    int candidate = stack[0];

    // Verify if the candidate is truly a celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // Candidate should not know anyone, and everyone should know the candidate
            if (knows(candidate, i) || !knows(i, candidate)) {
                free(stack);
                return -1; // No celebrity
            }
        }
    }

    free(stack);
    return candidate;
}

// Main function
int main() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    int celebrity = findCelebrity(n);
    if (celebrity == -1) {
        printf("No celebrity found\n");
    } else {
        printf("The celebrity is person %d\n", celebrity);
    }

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
