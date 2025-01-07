// Print the first k elements of a queue without altering its structure.
//  Print the First k Elements of a Queue
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

// Function to display the first k elements without altering the queue
void displayFirstKElements(int k) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    if (k > rear - front + 1) {
        printf("There are fewer than %d elements in the queue.\n", k);
        return;
    }
    printf("The first %d elements in the queue are: ", k);
    for (int i = front; i < front + k; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, k;

    // Example queue setup
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);

    printf("Enter the elements to enqueue:\n");
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        enqueue(element);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    displayFirstKElements(k);

    return 0;
}
