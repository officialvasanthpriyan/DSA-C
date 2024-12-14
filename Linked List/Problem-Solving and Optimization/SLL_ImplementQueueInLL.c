#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (!queue->rear) { // If the queue is empty
        queue->front = queue->rear = newNode;
        printf("%d enqueued to the queue\n", data);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d enqueued to the queue\n", data);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1; // Indicating queue is empty
    }
    struct Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = queue->front->next;

    if (!queue->front) { // If the queue is now empty
        queue->rear = NULL;
    }
    free(temp);
    return dequeuedData;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicating queue is empty
    }
    return queue->front->data;
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* temp = queue->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* queue = createQueue();

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;

            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("%d dequeued from the queue\n", value);
                }
                break;

            case 3:
                value = front(queue);
                if (value != -1) {
                    printf("Front element is %d\n", value);
                }
                break;

            case 4:
                displayQueue(queue);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
