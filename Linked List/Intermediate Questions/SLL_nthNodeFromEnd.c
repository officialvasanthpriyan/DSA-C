<<<<<<< HEAD
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

// Function to find the nth node from the end
struct Node* findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head;
    struct Node* second = head;

    // Move the `first` pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL) { // If n is greater than the length of the list
            printf("The list has fewer than %d nodes.\n", n);
            return NULL;
        }
        first = first->next;
    }

    // Move both pointers until the `first` pointer reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // `second` now points to the nth node from the end
    return second;
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

// Driver function
int main() {
    // Create a sample linked list: 10 -> 20 -> 30 -> 40 -> 50
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Linked List: ");
    printList(head);

    int n = 2;
    struct Node* nthNode = findNthFromEnd(head, n);
    if (nthNode != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthNode->data);
    }

    return 0;
}
=======
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

// Function to find the nth node from the end
struct Node* findNthFromEnd(struct Node* head, int n) {
    struct Node* first = head;
    struct Node* second = head;

    // Move the `first` pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (first == NULL) { // If n is greater than the length of the list
            printf("The list has fewer than %d nodes.\n", n);
            return NULL;
        }
        first = first->next;
    }

    // Move both pointers until the `first` pointer reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // `second` now points to the nth node from the end
    return second;
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

// Driver function
int main() {
    // Create a sample linked list: 10 -> 20 -> 30 -> 40 -> 50
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Linked List: ");
    printList(head);

    int n = 2;
    struct Node* nthNode = findNthFromEnd(head, n);
    if (nthNode != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthNode->data);
    }

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
