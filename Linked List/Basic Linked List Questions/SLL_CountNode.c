<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    // Traverse the list and count each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // Create a linked list with some initial nodes
    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);

    // Display the list
    printf("Linked List:\n");
    displayList(head);

    // Count and display the number of nodes
    int nodeCount = countNodes(head);
    printf("\nNumber of nodes in the linked list: %d\n", nodeCount);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    // Traverse the list and count each node
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // Create a linked list with some initial nodes
    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);

    // Display the list
    printf("Linked List:\n");
    displayList(head);

    // Count and display the number of nodes
    int nodeCount = countNodes(head);
    printf("\nNumber of nodes in the linked list: %d\n", nodeCount);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
