// Sort elements in a queue.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Function to append a value to the queue
void append(int val) {
    // Create a memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // Initialize the node memory
    newnode->data = val;
    newnode->next = NULL;

    // Check for the first node connection (head to first node)
    if (head == NULL) {
        head = newnode;
    }
    // (lastnode to newnode connection)
    else {
        struct Node *temp = head;
        // To find the last node
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

// Function to sort the queue
void sortQueue() {
    if (head == NULL || head->next == NULL) {
        return; // No need to sort
    }

    struct Node *i, *j;
    int temp;

    // Bubble sort for the linked list
    for (i = head; i->next != NULL; i = i->next) {
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                // Swap the data
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

int main() {
    int val;

    // Input the queue elements dynamically
    printf("Enter elements of the queue (-1 to stop):\n");
    do {
        scanf("%d", &val);
        if (val != -1)
            append(val);
    } while (val != -1);

    printf("Original Queue: ");
    display();

    sortQueue();

    printf("Sorted Queue: ");
    display();

    return 0;
}
