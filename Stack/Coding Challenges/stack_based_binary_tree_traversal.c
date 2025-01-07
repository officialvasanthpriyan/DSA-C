// Implement a stack-based traversal for binary trees (preorder, inorder, and postorder).
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Define the structure for a stack
typedef struct Stack {
    Node** arr;  // Array of Node pointers
    int top;     // Index of the top element
    int capacity;
} Stack;

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (Node**)malloc(capacity * sizeof(Node*));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push a node onto the stack
void push(Stack* stack, Node* node) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = node;
}

// Pop a node from the stack
Node* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

// Peek at the top node of the stack
Node* peek(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top];
}

// Preorder traversal using a stack
void preorderTraversal(Node* root) {
    if (!root) return;

    Stack* stack = createStack(100);  // Create a stack
    push(stack, root);

    printf("Preorder Traversal: ");
    while (!isEmpty(stack)) {
        Node* current = pop(stack);
        printf("%d ", current->data);

        // Push right child first so that left is processed first
        if (current->right) push(stack, current->right);
        if (current->left) push(stack, current->left);
    }
    printf("\n");

    free(stack->arr);
    free(stack);
}

// Inorder traversal using a stack
void inorderTraversal(Node* root) {
    Stack* stack = createStack(100);
    Node* current = root;

    printf("Inorder Traversal: ");
    while (!isEmpty(stack) || current != NULL) {
        // Reach the leftmost node
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        // Process the node
        current = pop(stack);
        printf("%d ", current->data);

        // Move to the right subtree
        current = current->right;
    }
    printf("\n");

    free(stack->arr);
    free(stack);
}

// Postorder traversal using two stacks
void postorderTraversal(Node* root) {
    if (!root) return;

    Stack* stack1 = createStack(100);
    Stack* stack2 = createStack(100);

    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* current = pop(stack1);
        push(stack2, current);

        if (current->left) push(stack1, current->left);
        if (current->right) push(stack1, current->right);
    }

    printf("Postorder Traversal: ");
    while (!isEmpty(stack2)) {
        Node* current = pop(stack2);
        printf("%d ", current->data);
    }
    printf("\n");

    free(stack1->arr);
    free(stack1);
    free(stack2->arr);
    free(stack2);
}

// Main function to test the traversals
int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform stack-based traversals
    preorderTraversal(root);
    inorderTraversal(root);
    postorderTraversal(root);

    // Free allocated memory (simple cleanup for this example)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
