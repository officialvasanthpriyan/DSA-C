#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data; // Data part of the node
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program if memory allocation fails 
        // The argument 1 is the exit status, indicating that the program terminated with an error (commonly, 0 indicates success).
    }
    newNode->data = value; // Assign the data
    newNode->next = NULL; // Set the next pointer to NULL
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List Elements: ");
    struct Node* temp = head; // Temporary pointer to traverse the list
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data
        temp = temp->next; // Move to the next node
    }
    printf("NULL\n"); // End of the list
}

int main() {
    struct Node* head = NULL; // Initialize the head of the list
    struct Node* temp = NULL; // Temporary pointer for construction

    int n, value; 
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value); // Create a new node

        if (head == NULL) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Otherwise, link the new node at the end of the list
            temp->next = newNode;
        }
        temp = newNode; // Update the temp pointer to the new node
    }

    // Display the linked list
    displayList(head);

    return 0;
}
