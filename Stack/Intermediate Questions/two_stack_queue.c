#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stacks
#define MAX 100

// Structure for the two-stack queue
typedef struct {
    int stack1[MAX];
    int stack2[MAX];
    int top1; // Top pointer for stack1
    int top2; // Top pointer for stack2
} TwoStackQueue;

// Initialize the queue
void initQueue(TwoStackQueue *queue) {
    queue->top1 = -1;
    queue->top2 = -1;
}

// Check if stack1 is empty
int isEmptyStack1(TwoStackQueue *queue) {
    return queue->top1 == -1;
}

// Check if stack2 is empty
int isEmptyStack2(TwoStackQueue *queue) {
    return queue->top2 == -1;
}

// Check if stack1 is full
int isFullStack1(TwoStackQueue *queue) {
    return queue->top1 == MAX - 1;
}

// Enqueue operation
void enqueue(TwoStackQueue *queue, int value) {
    if (isFullStack1(queue)) {
        printf("Queue overflow! Cannot enqueue %d.\n", value);
        return;
    }
    queue->stack1[++(queue->top1)] = value;
    printf("%d enqueued.\n", value);
}

// Dequeue operation
int dequeue(TwoStackQueue *queue) {
    if (isEmptyStack2(queue)) {
        // If stack2 is empty, transfer elements from stack1 to stack2
        if (isEmptyStack1(queue)) {
            printf("Queue underflow! Cannot dequeue.\n");
            return -1;
        }
        while (!isEmptyStack1(queue)) {
            queue->stack2[++(queue->top2)] = queue->stack1[(queue->top1)--];
        }
    }
    // Pop the top element from stack2
    return queue->stack2[(queue->top2)--];
}

// Main function to demonstrate the two-stack queue
int main() {
    TwoStackQueue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}
