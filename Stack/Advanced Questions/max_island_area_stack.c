// Find the maximum area of an island in a grid using stacks for Depth First Search (DFS).
#include <stdio.h>
#include <stdlib.h>

// Directions for up, down, left, and right
int rowDirections[] = {-1, 1, 0, 0};
int colDirections[] = {0, 0, -1, 1};

// Function to perform DFS using stack and calculate island area
int dfs(int** grid, int rows, int cols, int x, int y, int** visited) {
    // Stack for DFS
    int* stack = (int*)malloc(rows * cols * sizeof(int));  // stack array to hold coordinates
    int top = -1;
    int area = 0;
    
    // Push initial coordinates
    stack[++top] = x * cols + y;
    visited[x][y] = 1;

    while (top != -1) {
        // Pop from stack
        int current = stack[top--];
        int i = current / cols;  // row index
        int j = current % cols;  // column index
        area++;

        // Check four possible directions
        for (int k = 0; k < 4; k++) {
            int newX = i + rowDirections[k];
            int newY = j + colDirections[k];

            // Check if the new position is valid and is land (1) and not visited
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1 && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                stack[++top] = newX * cols + newY;  // Push the new position to the stack
            }
        }
    }

    free(stack);  // Free the stack after DFS
    return area;
}

// Function to find the maximum island area
int maxAreaOfIsland(int** grid, int rows, int cols) {
    int maxArea = 0;

    // Create a visited matrix
    int** visited = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        visited[i] = (int*)calloc(cols, sizeof(int)); // Initialize with 0
    }

    // Traverse the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                // If it's land and not visited, do DFS to calculate the area
                int area = dfs(grid, rows, cols, i, j, visited);
                maxArea = (area > maxArea) ? area : maxArea;  // Update max area
            }
        }
    }

    // Free visited matrix
    for (int i = 0; i < rows; i++) {
        free(visited[i]);
    }
    free(visited);

    return maxArea;
}

// Main function to test the solution
int main() {
    // Example grid (land = 1, water = 0)
    int grid[5][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 1, 0, 0}
    };

    int rows = 5;
    int cols = 5;
    
    // Convert the 2D array to a pointer to pointer for passing to functions
    int** gridPtr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        gridPtr[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            gridPtr[i][j] = grid[i][j];
        }
    }

    int maxArea = maxAreaOfIsland(gridPtr, rows, cols);
    printf("The maximum area of an island is: %d\n", maxArea);

    // Free the grid pointer
    for (int i = 0; i < rows; i++) {
        free(gridPtr[i]);
    }
    free(gridPtr);

    return 0;
}
