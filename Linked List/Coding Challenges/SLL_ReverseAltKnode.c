<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

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

// Function to reverse the k-group of nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    if (!head || k <= 1) return head;

    struct Node *current = head, *prev = NULL, *next = NULL;
    int count = 0;
    
    // Check if there are at least k nodes left to reverse
    struct Node* temp = head;
    for (count = 0; temp && count < k; count++) {
        temp = temp->next;
    }
    if (count < k) return head;  // If less than k nodes remain, return the head as is

    // Reverse first k nodes
    count = 0;
    while (current && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now, head points to the last node of the reversed part, connect it to the next part
    if (head) {
        head->next = current;  // Point the original head to the next node (after reversing k nodes)
    }

    // Skip the next k nodes and reverse the next group
    count = 0;
    while (current && count < k - 1) {
        current = current->next;
        count++;
    }

    // Recursively reverse alternate k-groups
    if (current) {
        current->next = reverseKGroup(current->next, k);  // Skip next k-group and reverse alternate ones
    }

    return prev;
}

// Function to print the list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a linked list with n nodes
struct Node* createList(int n) {
    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    return head;
}

int main() {
    int n = 10;
    struct Node* head = createList(n);

    printf("Original List:\n");
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    printf("Reversed Alternate Groups of %d:\n", k);
    printList(head);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

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

// Function to reverse the k-group of nodes
struct Node* reverseKGroup(struct Node* head, int k) {
    if (!head || k <= 1) return head;

    struct Node *current = head, *prev = NULL, *next = NULL;
    int count = 0;
    
    // Check if there are at least k nodes left to reverse
    struct Node* temp = head;
    for (count = 0; temp && count < k; count++) {
        temp = temp->next;
    }
    if (count < k) return head;  // If less than k nodes remain, return the head as is

    // Reverse first k nodes
    count = 0;
    while (current && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now, head points to the last node of the reversed part, connect it to the next part
    if (head) {
        head->next = current;  // Point the original head to the next node (after reversing k nodes)
    }

    // Skip the next k nodes and reverse the next group
    count = 0;
    while (current && count < k - 1) {
        current = current->next;
        count++;
    }

    // Recursively reverse alternate k-groups
    if (current) {
        current->next = reverseKGroup(current->next, k);  // Skip next k-group and reverse alternate ones
    }

    return prev;
}

// Function to print the list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a linked list with n nodes
struct Node* createList(int n) {
    struct Node* head = createNode(1);
    struct Node* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }

    return head;
}

int main() {
    int n = 10;
    struct Node* head = createList(n);

    printf("Original List:\n");
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    printf("Reversed Alternate Groups of %d:\n", k);
    printList(head);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
