#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to append a node to the linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!(*head)) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete all occurrences of a given key in the linked list
void deleteOccurrences(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    // Handle nodes at the head with the given key
    while (current && current->data == key) {
        *head = current->next; // Update the head
        free(current);
        current = *head; // Move to the next node
    }

    // Traverse the rest of the list
    while (current) {
        if (current->data == key) {
            prev->next = current->next; // Skip the current node
            free(current); // Free the memory of the node
        } else {
            prev = current; // Update the previous pointer
        }
        current = prev->next; // Move to the next node
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a linked list from user input
void createListFromUser(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(head, data);
    }
}

int main() {
    struct Node* head = NULL;
    int key;

    // Create a linked list from user input
    createListFromUser(&head);

    printf("The original linked list is:\n");
    printList(head);

    // Get the key to be deleted
    printf("Enter the key to delete: ");
    scanf("%d", &key);

    // Delete all occurrences of the key
    deleteOccurrences(&head, key);

    printf("The linked list after deletion is:\n");
    printList(head);

    return 0;
}
/*Enter the number of nodes: 7
Enter the elements of the linked list:
4
2
3
4
4
5
4
The original linked list is:
4 -> 2 -> 3 -> 4 -> 4 -> 5 -> 4 -> NULL
Enter the key to delete: 4
The linked list after deletion is:
2 -> 3 -> 5 -> NULL*/