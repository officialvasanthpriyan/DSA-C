// Check if a given sequence of operations (enqueue and dequeue) is valid for a queue.
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if the given sequence of operations is valid
int isValidSequence(const char *operations) {
    int queueSize = 0;  // Tracks the current size of the queue

    for (int i = 0; i < strlen(operations); i++) {
        if (operations[i] == 'E') {  // Enqueue operation
            queueSize++;
        } else if (operations[i] == 'D') {  // Dequeue operation
            if (queueSize == 0) {
                return 0;  // Invalid sequence, trying to dequeue from an empty queue
            }
            queueSize--;
        } else {
            return 0;  // Invalid character in the sequence
        }
    }

    return 1;  // If all operations are valid
}

int main() {
    char operations[MAX_SIZE];

    printf("Enter the sequence of operations (E for Enqueue, D for Dequeue): ");
    scanf("%s", operations);

    if (isValidSequence(operations)) {
        printf("The sequence of operations is valid for a queue.\n");
    } else {
        printf("The sequence of operations is NOT valid for a queue.\n");
    }

    return 0;
}
