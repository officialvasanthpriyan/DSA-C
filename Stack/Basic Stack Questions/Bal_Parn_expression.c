// Check for balanced parentheses in an expression using a stack
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

// Check if the character is an opening bracket
int isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

// Check if the characters are matching brackets
int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if the expression is balanced
int isBalanced(char *expression) {
    Stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (isOpeningBracket(ch)) {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch)) {
                return 0; // Not balanced
            }
        }
    }

    return isEmpty(&s); // Balanced if stack is empty at the end
}

int main() {
    char expression[MAX];

    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    if (isBalanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}
