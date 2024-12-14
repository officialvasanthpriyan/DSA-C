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

// Function to append a node to the end of a linked list
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

// Function to reverse k nodes in a linked list
struct Node* reverseKGroup(struct Node* head, int k) {
    if (!head || k <= 1) {
        return head;
    }

    struct Node *prev = NULL, *current = head, *next = NULL;
    int count = 0;

    // Check if there are at least k nodes to reverse
    struct Node* temp = head;
    for (count = 0; count < k && temp; count++) {
        temp = temp->next;
    }
    if (count < k) {
        return head;
    }

    count = 0;
    // Reverse k nodes
    while (current && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse the remaining list and connect
    if (next) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

// Function to print a linked list
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
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        appendNode(head, data);
    }
}

int main() {
    struct Node* head = NULL;
    int k;

    printf("Create the linked list:\n");
    createListFromUser(&head);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Modified List after reversing in groups of %d: ", k);
    printList(head);

    return 0;
}
