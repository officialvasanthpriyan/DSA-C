// Solve the "Circular Tour" problem using queues
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue node
struct QueueNode {
    int petrol;
    int distance;
    struct QueueNode *next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode *front, *rear;
} *queue = NULL;

// Function to create a new queue node
struct QueueNode* createNode(int petrol, int distance) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->petrol = petrol;
    newNode->distance = distance;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element into the queue
void enqueue(int petrol, int distance) {
    struct QueueNode *newNode = createNode(petrol, distance);

    if (queue == NULL) {
        queue = (struct Queue *)malloc(sizeof(struct Queue));
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to display the queue
void displayQueue() {
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("Petrol: %d, Distance: %d\n", temp->petrol, temp->distance);
        temp = temp->next;
    }
}

// Function to solve the circular tour problem
int circularTour() {
    if (queue == NULL || queue->front == NULL) {
        return -1;
    }

    int start = 0, curr_petrol = 0;
    struct QueueNode *temp = queue->front;
    struct QueueNode *original = temp; // Keep track of the original start point
    int index = 0;

    // Iterate through the queue to find the starting point
    do {
        curr_petrol += temp->petrol - temp->distance;

        if (curr_petrol < 0) {
            // If petrol becomes negative, move the start point forward
            start = index + 1;
            curr_petrol = 0;
        }

        temp = temp->next ? temp->next : queue->front;
        index++;
    } while (temp != original && start < index);

    // If the queue is traversed completely and petrol is sufficient
    if (curr_petrol >= 0) {
        return start;
    }
    return -1;
}

int main() {
    int petrol, distance;

    printf("Enter petrol and distance (Enter -1 -1 to stop):\n");
    do {
        scanf("%d %d", &petrol, &distance);
        if (petrol != -1 && distance != -1) {
            enqueue(petrol, distance);
        }
    } while (petrol != -1 && distance != -1);

    printf("\nQueue content:\n");
    displayQueue();

    int startPoint = circularTour();
    if (startPoint != -1) {
        printf("\nThe circular tour can start at petrol pump index: %d\n", startPoint);
    } else {
        printf("\nNo solution exists for the circular tour.\n");
    }

    return 0;
}
