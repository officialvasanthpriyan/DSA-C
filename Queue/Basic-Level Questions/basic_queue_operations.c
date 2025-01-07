// Perform basic operations (enqueue, dequeue, peek) on a queue.
#include <stdio.h>
#define SIZE 5  // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (rear == SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to add an element to the queue (enqueue)
void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    if (isEmpty()) {  // Initialize front when first element is added
        front = 0;
    }
    queue[++rear] = element;
    printf("Enqueued: %d\n", element);
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
    if (front > rear) {  // Reset the queue if it becomes empty
        front = rear = -1;
    }
}

// Function to get the front element of the queue (peek)
void peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
 