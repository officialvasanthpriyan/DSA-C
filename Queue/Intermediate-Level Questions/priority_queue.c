// Implement a priority queue.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Maximum size of the priority queue

typedef struct {
    int data;     // Value of the element
    int priority; // Priority of the element
} PriorityQueue;

PriorityQueue pq[SIZE];
int rear = -1; // Rear of the priority queue

// Function to check if the queue is empty
int isEmpty() {
    return (rear == -1);
}

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to add an element to the priority queue
void enqueue(int value, int priority) {
    if (isFull()) {
        printf("Priority queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    
    rear++;
    pq[rear].data = value;
    pq[rear].priority = priority;
    printf("Enqueued: %d with priority %d\n", value, priority);
}

// Function to remove and return the highest priority element
void dequeue() {
    if (isEmpty()) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }
    
    int highestPriorityIndex = 0;
    for (int i = 1; i <= rear; i++) {
        if (pq[i].priority < pq[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }
    
    printf("Dequeued: %d with priority %d\n", pq[highestPriorityIndex].data, pq[highestPriorityIndex].priority);

    // Shift the remaining elements
    for (int i = highestPriorityIndex; i < rear; i++) {
        pq[i] = pq[i + 1];
    }
    rear--;
}

// Function to display the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority queue is empty.\n");
        return;
    }
    
    printf("Priority Queue:\n");
    for (int i = 0; i <= rear; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, value, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                printf("Enter its priority: ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
