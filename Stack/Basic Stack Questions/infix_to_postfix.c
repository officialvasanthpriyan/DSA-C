// Convert an infix expression to a postfix expression.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// Peek the top element of the stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->arr[s->top];
}

// Check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Get the precedence of an operator
int precedence(char op) {
    if (op == '^') {
        return 3;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int j = 0; // Index for postfix array

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push onto stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        // If operator
        else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators from stack
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);

    // Remove newline character if present
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
