// Implement a circular buffer using a queue.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;  // Tail pointer for circular connection

int maxSize = 0;  // Maximum size of the circular buffer
int currentSize = 0;  // Current size of the circular buffer

// Function to append a value to the circular buffer
void append(int val) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;

    if (currentSize == maxSize) {
        // Buffer is full, overwrite the oldest element
        struct Node *temp = head;
        head = head->next;
        tail->next = head;  // Maintain the circular connection
        free(temp);  // Free the old node
        currentSize--;
    }

    if (head == NULL) {
        // First node
        newnode->next = newnode;  // Circular connection
        head = newnode;
        tail = newnode;
    } else {
        // Append to the end
        newnode->next = head;  // Maintain circular connection
        tail->next = newnode;
        tail = newnode;
    }

    currentSize++;
}

// Function to display the circular buffer
void display() {
    if (head == NULL) {
        printf("Buffer is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Buffer: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int val;

    printf("Enter the size of the circular buffer: ");
    scanf("%d", &maxSize);

    printf("Enter elements of the buffer (-1 to stop):\n");
    do {
        scanf("%d", &val);
        if (val != -1)
            append(val);
    } while (val != -1);

    display();

    return 0;
}
