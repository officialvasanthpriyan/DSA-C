// Implement a stack-based memory allocation system.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a memory block
typedef struct {
    int blockID;
    int size; // Size of the memory block in bytes
} MemoryBlock;

// Stack structure for memory blocks
typedef struct {
    MemoryBlock* blocks;
    int top;
    int capacity;
} MemoryStack;

// Function to create a memory stack
MemoryStack* createMemoryStack(int capacity) {
    MemoryStack* stack = (MemoryStack*)malloc(sizeof(MemoryStack));
    stack->blocks = (MemoryBlock*)malloc(capacity * sizeof(MemoryBlock));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Function to check if the stack is full
int isFull(MemoryStack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(MemoryStack* stack) {
    return stack->top == -1;
}

// Function to allocate a memory block
void allocateMemory(MemoryStack* stack, int blockID, int size) {
    if (isFull(stack)) {
        printf("Memory allocation failed: Stack is full!\n");
        return;
    }
    stack->blocks[++stack->top].blockID = blockID;
    stack->blocks[stack->top].size = size;
    printf("Allocated memory block %d of size %d bytes.\n", blockID, size);
}

// Function to deallocate the last memory block
void deallocateMemory(MemoryStack* stack) {
    if (isEmpty(stack)) {
        printf("Memory deallocation failed: No memory to deallocate!\n");
        return;
    }
    MemoryBlock block = stack->blocks[stack->top--];
    printf("Deallocated memory block %d of size %d bytes.\n", block.blockID, block.size);
}

// Function to display the memory stack
void displayMemoryStack(MemoryStack* stack) {
    if (isEmpty(stack)) {
        printf("Memory stack is empty.\n");
        return;
    }
    printf("Current memory stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("Block ID: %d, Size: %d bytes\n", stack->blocks[i].blockID, stack->blocks[i].size);
    }
}

// Main function to demonstrate the stack-based memory allocation system
int main() {
    int capacity, choice, blockID, size;

    // Input capacity of the memory stack
    printf("Enter the capacity of the memory stack: ");
    scanf("%d", &capacity);

    MemoryStack* memoryStack = createMemoryStack(capacity);

    // Menu-driven system
    while (1) {
        printf("\nMemory Allocation System Menu:\n");
        printf("1. Allocate Memory\n");
        printf("2. Deallocate Memory\n");
        printf("3. Display Memory Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter block ID: ");
                scanf("%d", &blockID);
                printf("Enter block size (in bytes): ");
                scanf("%d", &size);
                allocateMemory(memoryStack, blockID, size);
                break;

            case 2:
                deallocateMemory(memoryStack);
                break;

            case 3:
                displayMemoryStack(memoryStack);
                break;

            case 4:
                free(memoryStack->blocks);
                free(memoryStack);
                printf("Exiting memory allocation system.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
