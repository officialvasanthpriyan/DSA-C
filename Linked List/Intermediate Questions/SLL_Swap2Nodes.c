<<<<<<< HEAD
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to swap two nodes without swapping data
struct Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y) {
        printf("Both nodes have the same data. No swap needed.\n");
        return head;
    }

    struct Node *prevX = NULL, *currX = head;
    struct Node *prevY = NULL, *currY = head;

    // Find x and its previous node
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Find y and its previous node
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not found, return
    if (!currX || !currY) {
        printf("One or both elements not found. Swap not possible.\n");
        return head;
    }

    // If x is not the head, update prevX's next to point to currY
    if (prevX) {
        prevX->next = currY;
    } else { // Else make currY the new head
        head = currY;
    }

    // If y is not the head, update prevY's next to point to currX
    if (prevY) {
        prevY->next = currX;
    } else { // Else make currX the new head
        head = currX;
    }

    // Swap next pointers
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

// Function to traverse and display the linked list
void traverseList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, x, y;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Swap nodes\n4. Exit\nEnter your choice: ");
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
                printf("Enter the first node value to swap: ");
                scanf("%d", &x);
                printf("Enter the second node value to swap: ");
                scanf("%d", &y);
                head = swapNodes(head, x, y);
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

// Node structure for the singly linked list
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

// Function to insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to swap two nodes without swapping data
struct Node* swapNodes(struct Node* head, int x, int y) {
    if (x == y) {
        printf("Both nodes have the same data. No swap needed.\n");
        return head;
    }

    struct Node *prevX = NULL, *currX = head;
    struct Node *prevY = NULL, *currY = head;

    // Find x and its previous node
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Find y and its previous node
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not found, return
    if (!currX || !currY) {
        printf("One or both elements not found. Swap not possible.\n");
        return head;
    }

    // If x is not the head, update prevX's next to point to currY
    if (prevX) {
        prevX->next = currY;
    } else { // Else make currY the new head
        head = currY;
    }

    // If y is not the head, update prevY's next to point to currX
    if (prevY) {
        prevY->next = currX;
    } else { // Else make currX the new head
        head = currX;
    }

    // Swap next pointers
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

// Function to traverse and display the linked list
void traverseList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, x, y;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Swap nodes\n4. Exit\nEnter your choice: ");
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
                printf("Enter the first node value to swap: ");
                scanf("%d", &x);
                printf("Enter the second node value to swap: ");
                scanf("%d", &y);
                head = swapNodes(head, x, y);
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
