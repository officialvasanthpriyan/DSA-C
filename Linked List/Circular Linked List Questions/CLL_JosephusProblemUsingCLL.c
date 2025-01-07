#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL; // Initially points to NULL
    return newNode;
}

// Function to create a circular linked list with n nodes
struct Node* createCircularList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 1; i <= n; i++) {
        struct Node* newNode = createNode(i);
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    return head;
}

// Function to solve the Josephus problem
int josephus(struct Node* head, int k) {
    // Type Your Logic Here!!!
}

int main() {
    int n, k;

    // Input number of people and step count
    printf("Enter the number of people: \n");
    scanf("%d", &n);
    printf("Enter the step count (k): \n");
    scanf("%d", &k);

    // Create the circular linked list
    struct Node* head = createCircularList(n);

    // Solve the Josephus problem
    int winner = josephus(head, k);
    printf("The winner is person %d\n", winner);

    return 0;
}
