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

// Function to detect a loop in the linked list and find its length
int detectAndCountLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast) {
            int loopLength = 1;
            struct Node* temp = slow;
            while (temp->next != slow) {
                loopLength++;
                temp = temp->next;
            }
            return loopLength;
        }
    }
    return 0; // No loop
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

        if (i + 1 == *loopPosition) {
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
    printf("Enter the position to create a loop (0 for no loop): ");
    scanf("%d", &loopPosition);

    createListFromUser(&head, &loopPosition);

    int loopLength = detectAndCountLoop(head);
    if (loopLength > 0) {
        printf("Loop detected with length: %d\n", loopLength);
    } else {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
