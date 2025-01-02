#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
typedef struct Stack {
    char *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Push operation
void push(Stack* stack, char value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop operation
char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to validate the number
int isValidNumber(const char *str) {
    int i = 0;
    int n = strlen(str);
    int hasDecimal = 0, hasExponent = 0;

    // Ignore leading whitespaces
    while (i < n && isspace(str[i])) i++;

    // Optional sign
    if (i < n && (str[i] == '+' || str[i] == '-')) i++;

    // Create a stack
    Stack* stack = createStack(n);

    // Traverse the string
    for (; i < n; i++) {
        char c = str[i];

        // Ignore whitespace at the end
        if (isspace(c)) break;

        // Push digit characters to the stack
        if (isdigit(c)) {
            push(stack, c);
        } 
        // Handle decimal point
        else if (c == '.') {
            if (hasDecimal || hasExponent) {
                free(stack);
                return 0; // Multiple decimals or a decimal after exponent
            }
            hasDecimal = 1;
        } 
        // Handle exponent
        else if (c == 'e' || c == 'E') {
            if (hasExponent || isEmpty(stack)) {
                free(stack);
                return 0; // Multiple exponents or no digits before exponent
            }
            hasExponent = 1;
            hasDecimal = 1; // Decimal point not allowed after exponent
            if (i + 1 < n && (str[i + 1] == '+' || str[i + 1] == '-')) i++; // Skip optional sign
        } 
        // Invalid character
        else {
            free(stack);
            return 0;
        }
    }

    // Ignore trailing whitespaces
    while (i < n && isspace(str[i])) i++;

    // If stack is empty or trailing invalid characters
    int result = (!isEmpty(stack) && i == n);

    free(stack);
    return result;
}

// Main function
int main() {
    char input[100];
    printf("Enter a string to check if it's a valid number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    if (isValidNumber(input)) {
        printf("The string \"%s\" is a valid number.\n", input);
    } else {
        printf("The string \"%s\" is NOT a valid number.\n", input);
    }

    return 0;
}
