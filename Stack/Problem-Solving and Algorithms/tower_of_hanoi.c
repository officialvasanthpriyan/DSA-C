<<<<<<< HEAD
// Use a stack to implement Tower of Hanoi for n disks.
#include <stdio.h>
#include <stdlib.h>

// Structure for a stack
typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an item onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek at the top item of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Move a disk from source to destination
void moveDisk(char fromRod, char toRod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}

// Perform the actual move operation between two stacks
void moveBetweenStacks(Stack* src, Stack* dest, char srcRod, char destRod) {
    int srcTop = isEmpty(src) ? -1 : pop(src);
    int destTop = isEmpty(dest) ? -1 : pop(dest);

    // If the source stack is empty, move from destination to source
    if (srcTop == -1) {
        push(src, destTop);
        moveDisk(destRod, srcRod, destTop);
    }
    // If the destination stack is empty, move from source to destination
    else if (destTop == -1) {
        push(dest, srcTop);
        moveDisk(srcRod, destRod, srcTop);
    }
    // Compare the two top disks and move the smaller one on top of the larger one
    else if (srcTop > destTop) {
        push(src, srcTop);
        push(src, destTop);
        moveDisk(destRod, srcRod, destTop);
    } else {
        push(dest, destTop);
        push(dest, srcTop);
        moveDisk(srcRod, destRod, srcTop);
    }
}

// Implement the Tower of Hanoi using stacks
void towerOfHanoi(int numDisks, Stack* src, Stack* aux, Stack* dest) {
    char srcRod = 'A', auxRod = 'B', destRod = 'C';
    int totalMoves = (1 << numDisks) - 1; // 2^n - 1 moves required
    int i;

    // Initialize source rod with disks
    for (i = numDisks; i >= 1; i--) {
        push(src, i);
    }

    for (i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetweenStacks(src, dest, srcRod, destRod);
        } else if (i % 3 == 2) {
            moveBetweenStacks(src, aux, srcRod, auxRod);
        } else if (i % 3 == 0) {
            moveBetweenStacks(aux, dest, auxRod, destRod);
        }
    }
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Create three stacks for three rods
    Stack* src = createStack(numDisks);
    Stack* aux = createStack(numDisks);
    Stack* dest = createStack(numDisks);

    printf("Steps to solve the Tower of Hanoi:\n");
    towerOfHanoi(numDisks, src, aux, dest);

    // Clean up memory
    free(src->arr);
    free(src);
    free(aux->arr);
    free(aux);
    free(dest->arr);
    free(dest);

    return 0;
}
=======
// Use a stack to implement Tower of Hanoi for n disks.
#include <stdio.h>
#include <stdlib.h>

// Structure for a stack
typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Push an item onto the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Peek at the top item of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[stack->top];
}

// Move a disk from source to destination
void moveDisk(char fromRod, char toRod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, fromRod, toRod);
}

// Perform the actual move operation between two stacks
void moveBetweenStacks(Stack* src, Stack* dest, char srcRod, char destRod) {
    int srcTop = isEmpty(src) ? -1 : pop(src);
    int destTop = isEmpty(dest) ? -1 : pop(dest);

    // If the source stack is empty, move from destination to source
    if (srcTop == -1) {
        push(src, destTop);
        moveDisk(destRod, srcRod, destTop);
    }
    // If the destination stack is empty, move from source to destination
    else if (destTop == -1) {
        push(dest, srcTop);
        moveDisk(srcRod, destRod, srcTop);
    }
    // Compare the two top disks and move the smaller one on top of the larger one
    else if (srcTop > destTop) {
        push(src, srcTop);
        push(src, destTop);
        moveDisk(destRod, srcRod, destTop);
    } else {
        push(dest, destTop);
        push(dest, srcTop);
        moveDisk(srcRod, destRod, srcTop);
    }
}

// Implement the Tower of Hanoi using stacks
void towerOfHanoi(int numDisks, Stack* src, Stack* aux, Stack* dest) {
    char srcRod = 'A', auxRod = 'B', destRod = 'C';
    int totalMoves = (1 << numDisks) - 1; // 2^n - 1 moves required
    int i;

    // Initialize source rod with disks
    for (i = numDisks; i >= 1; i--) {
        push(src, i);
    }

    for (i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetweenStacks(src, dest, srcRod, destRod);
        } else if (i % 3 == 2) {
            moveBetweenStacks(src, aux, srcRod, auxRod);
        } else if (i % 3 == 0) {
            moveBetweenStacks(aux, dest, auxRod, destRod);
        }
    }
}

int main() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    // Create three stacks for three rods
    Stack* src = createStack(numDisks);
    Stack* aux = createStack(numDisks);
    Stack* dest = createStack(numDisks);

    printf("Steps to solve the Tower of Hanoi:\n");
    towerOfHanoi(numDisks, src, aux, dest);

    // Clean up memory
    free(src->arr);
    free(src);
    free(aux->arr);
    free(aux);
    free(dest->arr);
    free(dest);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
