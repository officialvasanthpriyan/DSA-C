<<<<<<< HEAD
// Use a stack to implement a calculator for basic mathematical expressions.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Define a stack structure
typedef struct {
    int top;
    double items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, double value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
double pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Peek at the top element of the stack
double peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Perform the given operation
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            printf("Invalid operator: %c\n", op);
            exit(EXIT_FAILURE);
    }
}

// Function to evaluate the given expression
double evaluateExpression(char* expression) {
    Stack values, operators;
    initStack(&values);
    initStack(&operators);

    int i = 0;
    while (expression[i] != '\0') {
        // Skip spaces
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        // If the current character is a number
        if (isdigit(expression[i])) {
            double value = 0;

            // Handle multiple digits
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }

            // If there's a decimal point
            if (expression[i] == '.') {
                i++;
                double decimalPlace = 0.1;
                while (i < strlen(expression) && isdigit(expression[i])) {
                    value += (expression[i] - '0') * decimalPlace;
                    decimalPlace /= 10;
                    i++;
                }
            }

            push(&values, value);
        }
        // If the current character is an open parenthesis
        else if (expression[i] == '(') {
            push(&operators, expression[i]);
            i++;
        }
        // If the current character is a closing parenthesis
        else if (expression[i] == ')') {
            while (!isEmpty(&operators) && peek(&operators) != '(') {
                double b = pop(&values);
                double a = pop(&values);
                char op = (char)pop(&operators);
                push(&values, applyOperation(a, b, op));
            }
            // Pop the opening parenthesis
            pop(&operators);
            i++;
        }
        // If the current character is an operator
        else {
            while (!isEmpty(&operators) && precedence((char)peek(&operators)) >= precedence(expression[i])) {
                double b = pop(&values);
                double a = pop(&values);
                char op = (char)pop(&operators);
                push(&values, applyOperation(a, b, op));
            }
            push(&operators, expression[i]);
            i++;
        }
    }

    // Perform remaining operations
    while (!isEmpty(&operators)) {
        double b = pop(&values);
        double a = pop(&values);
        char op = (char)pop(&operators);
        push(&values, applyOperation(a, b, op));
    }

    return pop(&values);
}

// Main function to test the calculator
int main() {
    char expression[MAX];

    printf("Enter a mathematical expression: ");
    fgets(expression, MAX, stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    double result = evaluateExpression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
=======
// Use a stack to implement a calculator for basic mathematical expressions.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Define a stack structure
typedef struct {
    int top;
    double items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, double value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
double pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Peek at the top element of the stack
double peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Perform the given operation
double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            printf("Invalid operator: %c\n", op);
            exit(EXIT_FAILURE);
    }
}

// Function to evaluate the given expression
double evaluateExpression(char* expression) {
    Stack values, operators;
    initStack(&values);
    initStack(&operators);

    int i = 0;
    while (expression[i] != '\0') {
        // Skip spaces
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        // If the current character is a number
        if (isdigit(expression[i])) {
            double value = 0;

            // Handle multiple digits
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = (value * 10) + (expression[i] - '0');
                i++;
            }

            // If there's a decimal point
            if (expression[i] == '.') {
                i++;
                double decimalPlace = 0.1;
                while (i < strlen(expression) && isdigit(expression[i])) {
                    value += (expression[i] - '0') * decimalPlace;
                    decimalPlace /= 10;
                    i++;
                }
            }

            push(&values, value);
        }
        // If the current character is an open parenthesis
        else if (expression[i] == '(') {
            push(&operators, expression[i]);
            i++;
        }
        // If the current character is a closing parenthesis
        else if (expression[i] == ')') {
            while (!isEmpty(&operators) && peek(&operators) != '(') {
                double b = pop(&values);
                double a = pop(&values);
                char op = (char)pop(&operators);
                push(&values, applyOperation(a, b, op));
            }
            // Pop the opening parenthesis
            pop(&operators);
            i++;
        }
        // If the current character is an operator
        else {
            while (!isEmpty(&operators) && precedence((char)peek(&operators)) >= precedence(expression[i])) {
                double b = pop(&values);
                double a = pop(&values);
                char op = (char)pop(&operators);
                push(&values, applyOperation(a, b, op));
            }
            push(&operators, expression[i]);
            i++;
        }
    }

    // Perform remaining operations
    while (!isEmpty(&operators)) {
        double b = pop(&values);
        double a = pop(&values);
        char op = (char)pop(&operators);
        push(&values, applyOperation(a, b, op));
    }

    return pop(&values);
}

// Main function to test the calculator
int main() {
    char expression[MAX];

    printf("Enter a mathematical expression: ");
    fgets(expression, MAX, stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    double result = evaluateExpression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
