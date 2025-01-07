// Rotate a queue to the left by k positions.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Function to append a value to the queue
void append(int val) {
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->next = NULL;
    // 3. Connection
    // Check for the first node connection (head to first node)
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        // Find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to display the queue
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to rotate the queue to the left by k positions
void rotateLeft(int k) {
    if (head == NULL || k <= 0) {
        return; // Nothing to rotate
    }

    struct Node *temp = head;
    int length = 1;

    // Find the length of the queue and the last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Connect the last node to the head to make it circular
    temp->next = head;

    // Find the new head after k rotations
    k = k % length; // Normalize k if it is greater than the length
    for (int i = 0; i < k; i++) {
        temp = temp->next;
    }

    // Update the head and break the circular link
    head = temp->next;
    temp->next = NULL;
}

int main() {
    int val, k;
    printf("Enter elements of the queue (-1 to stop):\n");
    do {
        scanf("%d", &val);
        if (val != -1)
            append(val);
    } while (val != -1);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original Queue: ");
    display();

    rotateLeft(k);

    printf("Queue after %d left rotations: ", k);
    display();

    return 0;
}
