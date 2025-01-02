// Solve the problem of removing k digits from a number to get the smallest possible number using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove `k` digits to form the smallest number
char* removeKDigits(char* num, int k) {
    int n = strlen(num);
    if (k >= n) {
        // If k is greater than or equal to the number of digits, the result is 0
        return strdup("0");
    }

    // Create a stack to store the digits of the resulting number
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    // Traverse the digits of the number
    for (int i = 0; i < n; i++) {
        // Remove digits from the stack that are greater than the current digit
        // to ensure the smallest possible number
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];  // Push the current digit onto the stack
    }

    // Remove remaining digits from the top if k > 0
    while (k > 0 && top >= 0) {
        top--;
        k--;
    }

    // Form the resulting number
    stack[++top] = '\0';

    // Remove leading zeros
    int start = 0;
    while (stack[start] == '0' && stack[start + 1] != '\0') {
        start++;
    }

    // Return the result
    char* result = strdup(stack + start);
    free(stack);

    return result;
}

int main() {
    char num[101];
    int k;

    // Input the number and the value of k
    printf("Enter the number: ");
    scanf("%s", num);
    printf("Enter the number of digits to remove (k): ");
    scanf("%d", &k);

    // Call the function to remove k digits
    char* result = removeKDigits(num, k);

    // Output the result
    printf("The smallest possible number is: %s\n", result);

    free(result);
    return 0;
}
