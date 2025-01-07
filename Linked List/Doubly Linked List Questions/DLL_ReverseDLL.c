<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap the prev and next pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which is previous now)
    }

    // Adjust the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, choice;

    // printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Get user input for the list
    for (int i = 0; i < n; i++) {
        // printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    traverseForward(head);

    reverseList(&head);
                
    traverseForward(head);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap the prev and next pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which is previous now)
    }

    // Adjust the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, choice;

    // printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Get user input for the list
    for (int i = 0; i < n; i++) {
        // printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    traverseForward(head);

    reverseList(&head);
                
    traverseForward(head);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
