<<<<<<< HEAD
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

// Function to rearrange the linked list in zigzag order
void rearrangeZigzag(struct Node* head) {
    if (!head || !head->next) return;

    int flag = 1; // 1 for '<', 0 for '>'
    struct Node* current = head;

    while (current->next) {
        if (flag) { // Expecting A < B
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        } else { // Expecting A > B
            if (current->data < current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
        flag = !flag; // Toggle flag
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    // Create the linked list from user input
    printf("Create the linked list:\n");
    createListFromUser(&head);

    printf("Original list:\n");
    printList(head);

    // Rearrange in zigzag order
    rearrangeZigzag(head);

    printf("List in zigzag order:\n");
    printList(head);

    return 0;
}
=======
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

// Function to rearrange the linked list in zigzag order
void rearrangeZigzag(struct Node* head) {
    if (!head || !head->next) return;

    int flag = 1; // 1 for '<', 0 for '>'
    struct Node* current = head;

    while (current->next) {
        if (flag) { // Expecting A < B
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        } else { // Expecting A > B
            if (current->data < current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
        flag = !flag; // Toggle flag
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    // Create the linked list from user input
    printf("Create the linked list:\n");
    createListFromUser(&head);

    printf("Original list:\n");
    printList(head);

    // Rearrange in zigzag order
    rearrangeZigzag(head);

    printf("List in zigzag order:\n");
    printList(head);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
