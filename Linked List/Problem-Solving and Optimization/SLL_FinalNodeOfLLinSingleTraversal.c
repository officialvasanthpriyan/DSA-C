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

// Function to find the middle node of the linked list
void findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Traverse the list with two pointers
    while (fast && fast->next) {
        slow = slow->next;         // Moves one step
        fast = fast->next->next;  // Moves two steps
    }

    if (slow) {
        printf("The middle node is: %d\n", slow->data);
    } else {
        printf("The linked list is empty.\n");
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

    // Create a linked list from user input
    createListFromUser(&head);

    printf("The linked list is:\n");
    printList(head);

    // Find and display the middle node
    findMiddle(head);

    return 0;
}
