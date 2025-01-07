// Generate binary numbers from 1 to n using a queue.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char data[SIZE][SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Queue functions
void enqueue(Queue* queue, char* value);
char* dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);
void initializeQueue(Queue* queue);

// Function to generate binary numbers from 1 to n
void generateBinaryNumbers(int n) {
    Queue queue;
    initializeQueue(&queue);

    // Enqueue the first binary number
    enqueue(&queue, "1");

    printf("Binary numbers from 1 to %d:\n", n);

    for (int i = 1; i <= n; i++) {
        // Dequeue the front element
        char* current = dequeue(&queue);
        printf("%s\n", current);

        // Generate the next two binary numbers and enqueue them
        char binary1[SIZE], binary2[SIZE];
        sprintf(binary1, "%s0", current);
        sprintf(binary2, "%s1", current);

        enqueue(&queue, binary1);
        enqueue(&queue, binary2);
    }
}

// Enqueue a string into the queue
void enqueue(Queue* queue, char* value) {
    if (queue->count == SIZE) {
        printf("Queue is full. Cannot enqueue '%s'.\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % SIZE;
    strcpy(queue->data[queue->rear], value);
    queue->count++;
}

// Dequeue a string from the queue
char* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    char* value = queue->data[queue->front];
    queue->front = (queue->front + 1) % SIZE;
    queue->count--;
    return value;
}

// Check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->count == 0;
}

// Initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Main function
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    generateBinaryNumbers(n);
    return 0;
}
