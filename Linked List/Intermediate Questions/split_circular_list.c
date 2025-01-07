#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a circular linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to split a circular linked list into two halves
void splitCircularList(Node* head, Node** head1, Node** head2) {
    if (head == NULL || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    Node *slow = head, *fast = head;

    // Find the middle using slow and fast pointers
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd number of nodes, move fast one step further
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Set head pointers for the two halves
    *head1 = head;
    *head2 = slow->next;

    // Make the first half circular
    slow->next = *head1;

    // Make the second half circular
    fast->next = *head2;
}

// Function to create a circular linked list from an array
Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    Node* head = createNode(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }

    // Make it circular
    tail->next = head;
    return head;
}

// Main function to test the splitting
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createCircularList(arr, n);
    printf("Original Circular Linked List:\n");
    printList(head);

    Node *head1 = NULL, *head2 = NULL;
    splitCircularList(head, &head1, &head2);

    printf("First Half:\n");
    printList(head1);

    printf("Second Half:\n");
    printList(head2);

    return 0;
}
