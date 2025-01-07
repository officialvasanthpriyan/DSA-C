// Implement a stack-based solution for solving the N-Queens problem.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for stack
typedef struct {
    int* arr;   // Array to store column positions of queens
    int top;    // Index of the top element in the stack
    int size;   // Size of the stack
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        stack->arr[i] = -1;  // Initialize stack array with -1
    }
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if a position is safe
bool isSafe(Stack* stack, int row, int col) {
    for (int i = 0; i <= stack->top; i++) {
        int prevRow = i;
        int prevCol = stack->arr[i];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

// Print the chessboard
void printSolution(Stack* stack, int n) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (stack->arr[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Solve the N-Queens problem using a stack
void solveNQueens(int n) {
    Stack* stack = createStack(n);
    int row = 0;

    while (1) {
        bool placed = false;

        // Determine the starting column for the current row
        int startCol = (isEmpty(stack) || row > stack->top) ? 0 : stack->arr[row] + 1;

        // Try placing a queen in the current row
        for (int col = startCol; col < n; col++) {
            if (isSafe(stack, row, col)) {
                if (row <= stack->top) {
                    stack->arr[row] = col;  // Update column if row is already in stack
                } else {
                    push(stack, col);       // Push column onto stack
                }
                placed = true;
                break;
            }
        }

        if (!placed) {
            // Backtrack if no valid column found
            if (isEmpty(stack)) {
                break;  // No more solutions to explore
            }
            row--;
            pop(stack);
        } else if (row == n - 1) {
            // Found a solution
            printSolution(stack, n);
            pop(stack);  // Backtrack to explore other solutions
        } else {
            // Proceed to the next row
            row++;
        }
    }

    // Cleanup
    free(stack->arr);
    free(stack);
}

int main() {
    int n;

    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid number of queens!\n");
        return 1;
    }

    solveNQueens(n);

    return 0;
}
