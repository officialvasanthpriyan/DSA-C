// Reverse a queue using a stack.
#include <stdio.h>
#include <stdlib.h>
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
    if (isEmpty()) {
        front = 0;
    }
    queue[++rear] = element;
    printf("Enqueued: %d\n", element);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate failure
    }
    int data = queue[front];
    front++;
    if (front > rear) {  // Reset queue when empty
        front = rear = -1;
    }
    return data;
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

// Function to reverse the queue using a stack
void reverseQueue() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to reverse.\n");
        return;
    }

    int stack[SIZE];
    int top = -1;

    // Dequeue all elements and push them onto the stack
    while (!isEmpty()) {
        stack[++top] = dequeue();
    }

    // Pop elements from the stack and enqueue them back into the queue
    while (top != -1) {
        enqueue(stack[top--]);
    }

    printf("Queue has been reversed.\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Reverse Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Validate input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n');  // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a valid integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                reverseQueue();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
