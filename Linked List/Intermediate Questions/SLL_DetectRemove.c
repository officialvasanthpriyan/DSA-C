<<<<<<< HEAD
// To detect and remove a loop in a linked list, we can use Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare Algorithm) for efficient detection and then modify the structure to remove the loop.
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect and remove a loop in the linked list
void detectAndRemoveLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Detect loop using Floyd's cycle detection algorithm
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {
            printf("Loop detected.\n");

            // Find the start of the loop
            slow = head;
            struct Node* prev = NULL; // To keep track of the last node in the loop
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Remove the loop
            printf("Removing loop...\n");
            prev->next = NULL;
            return;
        }
    }

    printf("No loop detected.\n");
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver function
int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40 -> 50 -> (points back to 30)
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Create a loop
    head->next->next->next->next->next = head->next->next; // 50 -> 30

    // Detect and remove the loop
    detectAndRemoveLoop(head);

    // Print the modified list
    printf("Linked List after loop removal: ");
    printList(head);

    return 0;
}
=======
// To detect and remove a loop in a linked list, we can use Floyd's Cycle Detection Algorithm (also known as the Tortoise and Hare Algorithm) for efficient detection and then modify the structure to remove the loop.
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect and remove a loop in the linked list
void detectAndRemoveLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Detect loop using Floyd's cycle detection algorithm
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {
            printf("Loop detected.\n");

            // Find the start of the loop
            slow = head;
            struct Node* prev = NULL; // To keep track of the last node in the loop
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Remove the loop
            printf("Removing loop...\n");
            prev->next = NULL;
            return;
        }
    }

    printf("No loop detected.\n");
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver function
int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40 -> 50 -> (points back to 30)
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Create a loop
    head->next->next->next->next->next = head->next->next; // 50 -> 30

    // Detect and remove the loop
    detectAndRemoveLoop(head);

    // Print the modified list
    printf("Linked List after loop removal: ");
    printList(head);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
