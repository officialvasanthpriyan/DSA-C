// Evaluate a postfix expression using a stack

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>23*54*+9-

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
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
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d.\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        exit(1); // Exit program due to error
    }
    return s->arr[(s->top)--];
}

// Evaluate a postfix expression
int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand, push onto stack
        if (isdigit(ch)) {
            push(&s, ch - '0'); // Convert char digit to int
        }
        // If operator, pop two elements and perform operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero error.\n");
                        exit(1);
                    }
                    result = operand1 / operand2; 
                    break;
                case '^': result = pow(operand1, operand2); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }

            push(&s, result);
        }
    }

    // Final result should be the only element left in the stack
    return pop(&s);
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX, stdin);

    // Remove newline character if present
    postfix[strcspn(postfix, "\n")] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
