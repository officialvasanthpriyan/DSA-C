// Use a stack to find the largest rectangle in a binary matrix.
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the largest rectangle in a histogram using a stack
int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));  // Stack to store column indices
    int top = -1;  // Initialize stack top
    int maxArea = 0;

    // Traverse the histogram
    for (int i = 0; i <= n; i++) {
        // Pop elements from stack while current height is smaller than the top of stack
        while (top != -1 && (i == n || heights[stack[top]] > heights[i])) {
            int h = heights[stack[top--]];  // Get the height at the top of stack
            int width = (top == -1) ? i : (i - stack[top] - 1);  // Calculate width
            int area = h * width;  // Calculate area
            if (area > maxArea) {
                maxArea = area;  // Update max area
            }
        }

        // Push the current index onto the stack
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}

// Function to find the largest rectangle in a binary matrix
int maximalRectangle(int** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int* heights = (int*)calloc(cols, sizeof(int));  // Array to store heights of histogram
    int maxArea = 0;

    // Iterate through each row
    for (int i = 0; i < rows; i++) {
        // Update the heights array based on the current row
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                heights[j] += 1;  // Increase height for 1
            } else {
                heights[j] = 0;   // Reset height for 0
            }
        }

        // Debug: Print the updated heights array for this row
        printf("Heights after row %d: ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%d ", heights[j]);
        }
        printf("\n");

        // Call the function to compute the largest rectangle in this histogram (row-wise)
        int area = largestRectangleArea(heights, cols);
        if (area > maxArea) {
            maxArea = area;  // Update the max area
        }
    }

    free(heights);
    return maxArea;
}

int main() {
    int rows, cols;

    // Input number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check for valid input
    if (rows <= 0 || cols <= 0) {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    // Dynamically allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Input matrix elements
    printf("Enter the binary matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call the function to compute the largest rectangle
    int maxArea = maximalRectangle(matrix, rows, cols);
    printf("The largest rectangle area is: %d\n", maxArea);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

