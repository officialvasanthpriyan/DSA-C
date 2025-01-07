// Find the first non-repeating character in a stream of characters using a queue.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 256

typedef struct {
    char data[MAX_CHARS];
    int front;
    int rear;
    int count;
} Queue;

// Queue functions
void enqueue(Queue* queue, char value);
char dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);
void initializeQueue(Queue* queue);

// Function to find the first non-repeating character
void findFirstNonRepeating(char* stream) {
    int charCount[MAX_CHARS] = {0}; // Array to store the frequency of each character
    Queue queue;
    initializeQueue(&queue);

    printf("Processing stream: %s\n", stream);
    for (int i = 0; stream[i] != '\0'; i++) {
        char currentChar = stream[i];
        charCount[currentChar]++;

        // Add the character to the queue
        enqueue(&queue, currentChar);

        // Remove characters from the front of the queue if they are repeated
        while (!isQueueEmpty(&queue) && charCount[queue.data[queue.front]] > 1) {
            dequeue(&queue);
        }

        // Display the first non-repeating character
        if (isQueueEmpty(&queue)) {
            printf("After reading '%c': No non-repeating character\n", currentChar);
        } else {
            printf("After reading '%c': First non-repeating character is '%c'\n",
                   currentChar, queue.data[queue.front]);
        }
    }
}

// Enqueue a character into the queue
void enqueue(Queue* queue, char value) {
    if (queue->count == MAX_CHARS) {
        printf("Queue is full. Cannot enqueue '%c'.\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_CHARS;
    queue->data[queue->rear] = value;
    queue->count++;
}

// Dequeue a character from the queue
char dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return '\0';
    }
    char value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_CHARS;
    queue->count--;
    return value;
}

// Check if the queue is empty
bool isQueueEmpty(Queue* queue) {
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
    char stream[] = "aabcdeafgh";
    findFirstNonRepeating(stream);
    return 0;
}

