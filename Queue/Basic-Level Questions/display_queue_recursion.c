// Display the elements of a queue without using a loop (recursion-based).
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
}

// Recursive function to display the elements of the queue
void displayRecursively(int index) {
    if (index > rear) {
        return;  // Base case: Stop when the index goes beyond rear
    }
    printf("%d ", queue[index]);
    displayRecursively(index + 1);  // Recursive call to display the next element
}

// Wrapper function to initiate the recursive display
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    displayRecursively(front);  // Start recursion from the front index
    printf("\n");
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

    // Display the queue using recursion
    displayQueue();

    return 0;
}
