// Decode a string with nested patterns (e.g., "3[a2[c]]" -> "accaccacc") using a stack.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for stack elements
typedef struct {
    char* str;      // Holds the current decoded string
    int repeat;     // Holds the repeat count
} StackElement;

// Structure for stack
typedef struct {
    StackElement* elements;
    int top;
    int capacity;
} Stack;

// Create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->elements = (StackElement*)malloc(capacity * sizeof(StackElement));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, const char* str, int repeat) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->elements[stack->top].str = strdup(str);
    stack->elements[stack->top].repeat = repeat;
}

// Pop an element from the stack
StackElement pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top--];
}

// Peek at the top element of the stack
StackElement peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->elements[stack->top];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Decode the given string
char* decodeString(const char* s) {
    Stack* stack = createStack(100);
    char* currentStr = strdup("");  // Current decoded string
    int num = 0;                   // Current number

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            // Build the number
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            // Push the current state onto the stack
            push(stack, currentStr, num);
            free(currentStr);
            currentStr = strdup("");  // Reset the current string
            num = 0;                  // Reset the number
        } else if (s[i] == ']') {
            // Pop the top element from the stack
            StackElement top = pop(stack);

            // Repeat the current string and append to the previous
            int repeat = top.repeat;
            char* temp = (char*)malloc(strlen(currentStr) * repeat + 1);
            temp[0] = '\0';
            for (int j = 0; j < repeat; j++) {
                strcat(temp, currentStr);
            }

            char* newStr = (char*)malloc(strlen(top.str) + strlen(temp) + 1);
            strcpy(newStr, top.str);
            strcat(newStr, temp);

            free(currentStr);
            free(top.str);
            free(temp);

            currentStr = newStr;
        } else {
            // Append the current character to the current string
            size_t len = strlen(currentStr);
            currentStr = (char*)realloc(currentStr, len + 2);
            currentStr[len] = s[i];
            currentStr[len + 1] = '\0';
        }
    }

    // Cleanup
    free(stack->elements);
    free(stack);
    return currentStr;
}

// Main function
int main() {
    char input[100];

    printf("Enter the encoded string: ");
    scanf("%s", input);

    char* decodedString = decodeString(input);
    printf("Decoded string: %s\n", decodedString);

    free(decodedString);
    return 0;
}
