#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
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

// Function to insert a node at the end of the singly linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode; // The new node is the head
    }
    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to make the list circular
struct Node* makeCircular(struct Node* head) {
    if (!head) {
        printf("List is empty. Cannot make it circular.\n");
        return head;
    }
    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = head; // Connect the last node to the head
    printf("The list has been made circular.\n");
    return head;
}

// Function to check if a singly linked list is circular
int isCircular(struct Node* head) {
    if (!head) {
        return 0; // An empty list is not circular
    }
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // The list is circular
        }
    }
    return 0; // The list is not circular
}

// Function to traverse and display the singly linked list
void traverseList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current && current != head); // Stop if circular and revisit head
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Check if circular\n4. Make list circular\n5. Exit\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 2:
                traverseList(head);
                break;
            case 3:
                if (isCircular(head)) {
                    printf("The list is circular.\n");
                } else {
                    printf("The list is not circular.\n");
                }
                break;
            case 4:
                head = makeCircular(head);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
