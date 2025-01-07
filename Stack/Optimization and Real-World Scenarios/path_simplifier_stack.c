// Use a stack to validate and simplify a file system path (e.g., "/home/../user/./code" -> "/user/code").
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define stack structure
typedef struct {
    char** arr;  // Array of strings to hold path components
    int top;     // Index of the top element in the stack
    int size;    // Size of the stack
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (char**)malloc(size * sizeof(char*));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, char* value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = strdup(value);
}

// Pop an element from the stack
char* pop(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Free the stack
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        free(pop(stack));
    }
    free(stack->arr);
    free(stack);
}

// Function to simplify a file system path
char* simplifyPath(char* path) {
    Stack* stack = createStack(100);  // Initialize stack with sufficient size
    char* token = strtok(path, "/");  // Tokenize the path by "/"
    char* simplifiedPath = (char*)malloc(1024);

    // Process each component of the path
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            // ".." means go back one directory, pop the stack
            if (!isEmpty(stack)) {
                free(pop(stack));
            }
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            // Ignore "." and empty tokens, otherwise push the directory name
            push(stack, token);
        }
        token = strtok(NULL, "/");
    }

    // Build the simplified path from the stack
    simplifiedPath[0] = '\0';
    if (isEmpty(stack)) {
        strcat(simplifiedPath, "/");
    } else {
        while (!isEmpty(stack)) {
            char* dir = pop(stack);
            strcat(simplifiedPath, "/");
            strcat(simplifiedPath, dir);
            free(dir);
        }
    }

    freeStack(stack);
    return simplifiedPath;
}

int main() {
    char path[1024];

    printf("Enter the file system path: ");
    scanf("%s", path);

    char* simplifiedPath = simplifyPath(path);
    printf("Simplified Path: %s\n", simplifiedPath);

    free(simplifiedPath);
    return 0;
}
