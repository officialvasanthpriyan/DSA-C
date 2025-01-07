// Interleave the first half and the second half of a queue
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Function to append a value to the queue
void append(int val) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
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

// Function to interleave the first half and the second half of the queue
void interleaveQueue() {
    if (head == NULL || head->next == NULL) {
        return; // Nothing to interleave
    }

    // Find the middle of the queue
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the queue into two halves
    struct Node *secondHalf = slow->next;
    slow->next = NULL;

    // Interleave the two halves
    struct Node *firstHalf = head;
    struct Node *temp1, *temp2;
    while (firstHalf != NULL && secondHalf != NULL) {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
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

    interleaveQueue();

    printf("Interleaved Queue: ");
    display();

    return 0;
}
