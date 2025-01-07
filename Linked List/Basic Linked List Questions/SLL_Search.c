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

// Function to search for a value in the linked list
int searchValue(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1; // Position starts at 1 (not 0)

    // Traverse the list and search for the value
    while (temp != NULL) {
        if (temp->data == value) {
            return position; // Return the position if value is found
        }
        temp = temp->next;
        position++;
    }

    return -1; // Return -1 if value is not found
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

    // Search for a value in the linked list
    int valueToSearch;
    printf("\nEnter the value to search: ");
    scanf("%d", &valueToSearch);

    int position = searchValue(head, valueToSearch);
    if (position != -1) {
        printf("Value %d found at position %d.\n", valueToSearch, position);
    } else {
        printf("Value %d not found in the list.\n", valueToSearch);
    }

    return 0;
}
