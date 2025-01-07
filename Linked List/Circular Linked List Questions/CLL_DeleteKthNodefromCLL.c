<<<<<<< HEAD
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

// Function to insert a node at the end of the circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        newNode->next = newNode; // Point to itself, making it circular
        return newNode;
    }
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

// Function to delete the kth node from the circular linked list
struct Node* deleteKthNode(struct Node* head, int k) {
    if (!head) {
        printf("\nList is empty. Nothing to delete.\n");
        return NULL;
    }
    if (k <= 0) {
        printf("Invalid position. Please enter a valid position.\n");
        return head;
    }
    struct Node* current = head;
    struct Node* previous = NULL;

    // Special case: Deleting the head node
    if (k == 1) {
        while (current->next != head) {
            current = current->next;
        }
        if (current == head) { // Only one node in the list
            free(head);
            return NULL;
        }
        current->next = head->next;
        free(head);
        return current->next;
    }

    // Traverse to the kth node
    for (int i = 1; i < k && current->next != head; i++) {
        previous = current;
        current = current->next;
    }

    // If k is out of bounds
    if (current == head) {
        printf("Position out of bounds. No node deleted.\n");
        return head;
    }

    // Delete the kth node
    previous->next = current->next;
    free(current);
    return head;
}

// Function to traverse and display the circular linked list
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
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, k;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Delete kth node\n4. Exit\nEnter your choice: \n");
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
                printf("Enter the position (k) of the node to delete: ");
                scanf("%d", &k);
                head = deleteKthNode(head, k);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
=======
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

// Function to insert a node at the end of the circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        newNode->next = newNode; // Point to itself, making it circular
        return newNode;
    }
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

// Function to delete the kth node from the circular linked list
struct Node* deleteKthNode(struct Node* head, int k) {
    if (!head) {
        printf("\nList is empty. Nothing to delete.\n");
        return NULL;
    }
    if (k <= 0) {
        printf("Invalid position. Please enter a valid position.\n");
        return head;
    }
    struct Node* current = head;
    struct Node* previous = NULL;

    // Special case: Deleting the head node
    if (k == 1) {
        while (current->next != head) {
            current = current->next;
        }
        if (current == head) { // Only one node in the list
            free(head);
            return NULL;
        }
        current->next = head->next;
        free(head);
        return current->next;
    }

    // Traverse to the kth node
    for (int i = 1; i < k && current->next != head; i++) {
        previous = current;
        current = current->next;
    }

    // If k is out of bounds
    if (current == head) {
        printf("Position out of bounds. No node deleted.\n");
        return head;
    }

    // Delete the kth node
    previous->next = current->next;
    free(current);
    return head;
}

// Function to traverse and display the circular linked list
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
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, k;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Delete kth node\n4. Exit\nEnter your choice: \n");
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
                printf("Enter the position (k) of the node to delete: ");
                scanf("%d", &k);
                head = deleteKthNode(head, k);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
