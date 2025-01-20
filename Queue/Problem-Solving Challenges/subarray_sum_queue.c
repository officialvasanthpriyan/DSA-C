// Use a queue to find all subarrays with a sum greater than a given value.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Function to append a value to the queue
void append(int val) {
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    // 2. Initialize the node
    newnode->data = val;
    newnode->next = NULL;

    // 3. Connection: If it's the first node, make it the head
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode; // Connect the last node to the new node
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

// Function to find and display all subarrays with a sum greater than the given value
void findSubarrays(int targetSum) {
    struct Node *start = head, *end;
    int sum;

    printf("Subarrays with sum greater than %d:\n", targetSum);
    while (start != NULL) {
        sum = 0;
        end = start;

        // Compute subarray sums starting from 'start'
        while (end != NULL) {
            sum += end->data;
            if (sum > targetSum) {
                // Print the current subarray
                struct Node *temp = start;
                printf("[ ");
                while (temp != end->next) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("]\n");
            }
            end = end->next;
        }
        start = start->next;
    }
}

int main() {
    int val, targetSum;

    printf("Enter elements of the queue (Enter -1 to stop):\n");
    do {
        scanf("%d", &val);
        if (val != -1) {
            append(val);
        }
    } while (val != -1);

    printf("\nQueue content:\n");
    display();

    printf("Enter the target sum:\n");
    scanf("%d", &targetSum);

    // Find and display subarrays
    findSubarrays(targetSum);

    return 0;
}
