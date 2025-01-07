<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push '%c'.\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Reverse a string using a stack
void reverseString(char *str) {
    Stack s;
    initStack(&s);

    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop characters from the stack and overwrite the string
    for (int i = 0; !isEmpty(&s); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string to reverse: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push '%c'.\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Reverse a string using a stack
void reverseString(char *str) {
    Stack s;
    initStack(&s);

    // Push all characters of the string onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        push(&s, str[i]);
    }

    // Pop characters from the stack and overwrite the string
    for (int i = 0; !isEmpty(&s); i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string to reverse: ");
    fgets(str, MAX, stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
