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

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* temp;

    // Create a hash table (assuming node data is in a reasonable range)
    int hashTable[1000] = {0};  // Change the size of the array if needed

    while (current != NULL) {
        // If the value has been encountered before, remove the current node
        if (hashTable[current->data] == 1) {
            prev->next = current->next;  // Bypass the current node
            free(current);  // Free the current node
            current = prev->next;  // Move to the next node
        } else {
            // Otherwise, mark the value as seen in the hash table
            hashTable[current->data] = 1;
            prev = current;
            current = current->next;  // Move to the next node
        }
    }
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

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data;

    // Take input for the number of nodes in the linked list
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    // Take input for each node value
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    // Remove duplicates from the linked list
    removeDuplicates(head);

    printf("\nLinked List after removing duplicates:\n");
    printList(head);

    return 0;
}
