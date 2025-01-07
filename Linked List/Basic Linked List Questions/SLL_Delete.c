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

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) { // Only one node
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node from the middle
struct Node* deleteFromMiddle(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    if (position == 1) {
        return deleteFromBeginning(head);
    }
    struct Node* temp = head;
    int count = 1;

    // Traverse to the node just before the desired position
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // Insert some initial nodes
    head = createNode(10);
    temp = head;
    temp->next = createNode(20);
    temp = temp->next;
    temp->next = createNode(30);
    temp = temp->next;
    temp->next = createNode(40);

    printf("Initial list:\n");
    displayList(head);

    // Delete from the beginning
    printf("\nDeleting from the beginning...\n");
    head = deleteFromBeginning(head);
    displayList(head);

    // Delete from the end
    printf("\nDeleting from the end...\n");
    head = deleteFromEnd(head);
    displayList(head);

    // Delete from the middle
    int position;
    printf("\nDeleting from the middle...\nEnter position to delete: ");
    scanf("%d", &position);
    head = deleteFromMiddle(head, position);
    displayList(head);

    return 0;
}
