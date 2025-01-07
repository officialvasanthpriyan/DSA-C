// Count the number of elements in a queue.
#include <stdio.h>
#define SIZE 10  // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to add an element to the queue (enqueue)
void enqueue(int element) {
    if (rear == SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    queue[++rear] = element;
    printf("Enqueued: %d\n", element);
}

// Function to count the number of elements in the queue
int countElements() {
    if (isEmpty()) {
        return 0;
    }
    return (rear - front + 1);
}

int main() {
    int n;

    // Example queue setup
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter the elements to enqueue:\n");
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        enqueue(element);
    }

    // Count the number of elements in the queue
    int count = countElements();
    printf("The number of elements in the queue is: %d\n", count);

    return 0;
}
