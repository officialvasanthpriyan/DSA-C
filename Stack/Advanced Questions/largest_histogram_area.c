// Find the largest rectangular area in a histogram using a stack.
#include <stdio.h>
#include <stdlib.h>

// Function to find the largest rectangular area in a histogram
int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc(n * sizeof(int)); // Stack to store indices
    int top = -1;                              // Top of the stack
    int maxArea = 0;                           // Maximum rectangular area
    int i = 0;

    while (i < n) {
        // Push the current bar's index onto the stack if it's greater than or equal to the bar at the top of the stack
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i++;
        } else {
            // Pop the top of the stack
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = (height * width > maxArea) ? height * width : maxArea;
        }
    }

    // Process remaining elements in the stack
    while (top != -1) {
        int height = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        maxArea = (height * width > maxArea) ? height * width : maxArea;
    }

    free(stack);
    return maxArea;
}

// Driver function
int main() {
    int n;
    printf("Enter the number of bars in the histogram: ");
    scanf("%d", &n);

    int* heights = (int*)malloc(n * sizeof(int));
    printf("Enter the heights of the bars: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    int maxArea = largestRectangleArea(heights, n);
    printf("The largest rectangular area in the histogram is: %d\n", maxArea);

    free(heights);
    return 0;
}
