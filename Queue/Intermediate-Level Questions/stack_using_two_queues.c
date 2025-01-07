// Implement a stack using two queues.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int data[SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function prototypes
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
void push(Queue* queue1, Queue* queue2, int value);
int pop(Queue* queue1, Queue* queue2);
int peek(Queue* queue1);
void display(Queue* queue1);

// Enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    queue->data[queue->rear] = value;
    queue->count++;
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % SIZE;
    queue->count--;
    return value;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->count == 0);
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->count == SIZE);
}

// Push operation: Add an element to the stack
void push(Queue* queue1, Queue* queue2, int value) {
    enqueue(queue1, value);
    printf("Pushed: %d\n", value);
}

// Pop operation: Remove the top element from the stack
int pop(Queue* queue1, Queue* queue2) {
    if (isEmpty(queue1)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    while (queue1->count > 1) {
        enqueue(queue2, dequeue(queue1));
    }

    int top = dequeue(queue1);

    Queue* temp = queue1;
    queue1 = queue2;
    queue2 = temp;

    return top;
}

// Peek operation: Get the top element of the stack without removing it
int peek(Queue* queue1) {
    if (isEmpty(queue1)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }

    int value;
    int size = queue1->count;

    for (int i = 0; i < size; i++) {
        value = dequeue(queue1);
        enqueue(queue1, value);
    }

    return value;
}

// Display the elements in the stack
void display(Queue* queue1) {
    Queue temp = *queue1;

    printf("Stack elements: ");
    while (!isEmpty(&temp)) {
        printf("%d ", dequeue(&temp));
    }
    printf("\n");
}

// Main function
int main() {
    Queue queue1 = {.front = 0, .rear = -1, .count = 0};
    Queue queue2 = {.front = 0, .rear = -1, .count = 0};

    int choice, value;

    while (1) {
        printf("\nStack Operations Using Two Queues:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&queue1, &queue2, value);
                break;
            case 2:
                value = pop(&queue1, &queue2);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                value = peek(&queue1);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display(&queue1);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
