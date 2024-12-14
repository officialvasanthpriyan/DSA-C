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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to rotate the linked list to the left by k positions
struct Node* rotateLeft(struct Node* head, int k) {
    if (head == NULL || k <= 0) {
        return head;
    }

    struct Node* current = head;
    int length = 1;

    // Find the length of the list
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Find the new head after k rotations
    k = k % length; // In case k is greater than the length
    int skip = length - k;
    struct Node* newHead = head;
    struct Node* prev = NULL;
    while (skip > 0) {
        prev = newHead;
        newHead = newHead->next;
        skip--;
    }

    // Break the circular list
    prev->next = NULL;

    return newHead;
}

// Function to rotate the linked list to the right by k positions
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || k <= 0) {
        return head;
    }

    struct Node* current = head;
    int length = 1;

    // Find the length of the list
    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to form a circular list
    current->next = head;

    // Find the new head after k rotations
    k = k % length; // In case k is greater than the length
    int skip = length - k;
    struct Node* newHead = head;
    struct Node* prev = NULL;
    while (skip > 0) {
        prev = newHead;
        newHead = newHead->next;
        skip--;
    }

    // Break the circular list
    prev->next = NULL;

    return newHead;
}

int main() {
    struct Node* head = NULL;
    int n, data, k, direction;

    // Input the number of nodes in the linked list
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    // Input the values for each node
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("\nOriginal Linked List:\n");
    printList(head);

    // Input the rotation direction and number of positions
    printf("\nEnter the direction of rotation (0 for left, 1 for right): ");
    scanf("%d", &direction);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Perform the rotation
    if (direction == 0) {
        head = rotateLeft(head, k);
        printf("\nLinked List after left rotation by %d positions:\n", k);
    } else {
        head = rotateRight(head, k);
        printf("\nLinked List after right rotation by %d positions:\n", k);
    }

    // Print the rotated linked list
    printList(head);

    return 0;
}
