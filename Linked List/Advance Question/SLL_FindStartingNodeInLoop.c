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

// Function to find the starting node of the loop
struct Node* findLoopStart(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: Detect the loop using Floyd's Cycle Detection Algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Loop detected
            break;
        }
    }

    if (!fast || !fast->next) { // No loop
        return NULL;
    }

    // Step 2: Find the starting node of the loop
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Starting node of the loop
}

// Function to create a linked list from user input
void createListFromUser(struct Node** head, int* loopPosition) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* loopNode = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        appendNode(head, data);

        if (i == *loopPosition - 1) {
            loopNode = *head;
            while (loopNode->next) {
                loopNode = loopNode->next;
            }
        }

        tail = *head;
        while (tail->next) {
            tail = tail->next;
        }
    }

    if (*loopPosition > 0 && loopNode) {
        tail->next = loopNode; // Creating the loop
    }
}

int main() {
    struct Node* head = NULL;
    int loopPosition;

    printf("Create the linked list:\n");
    createListFromUser(&head, &loopPosition);

    printf("Enter the position to create a loop (0 for no loop): ");
    scanf("%d", &loopPosition);

    struct Node* loopStart = findLoopStart(head);

    if (loopStart) {
        printf("The loop starts at node with data: %d\n", loopStart->data);
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
