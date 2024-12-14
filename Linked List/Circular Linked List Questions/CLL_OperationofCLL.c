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
    newNode->next = newNode; // Points to itself for a circular structure
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertEnd(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    if (!tail) {
        return newNode; // The new node is both the head and the tail
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return newNode; // Update tail to the new node
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertBegin(struct Node* tail, int data) {
    struct Node* newNode = createNode(data);
    if (!tail) {
        return newNode; // The new node is both the head and the tail
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail; // Tail remains the same
}

// Function to insert a node at the middle of the circular linked list
struct Node* insertMid(struct Node* tail, int data, int pos) {
    if (!tail) {
        printf("List is empty. Inserting at the beginning.\n");
        return insertBegin(tail, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* current = tail->next;
    int count = 1;
    while (count < pos - 1 && current != tail) {
        current = current->next;
        count++;
    }
    newNode->next = current->next;
    current->next = newNode;
    if (current == tail) {
        tail = newNode;
    }
    return tail;
}

// Function to delete a node from the circular linked list
struct Node* deleteNode(struct Node* tail, int key) {
    if (!tail) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node* current = tail->next;
    struct Node* prev = tail;
    do {
        if (current->data == key) {
            if (current == tail && current->next == tail) {
                // Only one node in the list
                free(current);
                return NULL;
            }
            if (current == tail) {
                // Deleting the tail node
                prev->next = tail->next;
                tail = prev;
            } else {
                prev->next = current->next;
            }
            free(current);
            return tail;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);

    printf("Key not found.\n");
    return tail;
}

// Function to delete a node at a specific position from the circular linked list
struct Node* deleteAtMid(struct Node* tail, int pos) {
    if (!tail) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* current = tail->next;
    struct Node* prev = tail;
    int count = 1;
    do {
        if (count == pos) {
            if (current == tail && current->next == tail) {
                // Only one node in the list
                free(current);
                return NULL;
            }
            if (current == tail) {
                prev->next = tail->next;
                tail = prev;
            } else {
                prev->next = current->next;
            }
            free(current);
            return tail;
        }
        prev = current;
        current = current->next;
        count++;
    } while (current != tail->next);

    printf("Invalid position.\n");
    return tail;
}

// Function to traverse and display the circular linked list
void traverseList(struct Node* tail) {
    if (!tail) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = tail->next;
    printf("List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}

int main() {
    struct Node* tail = NULL;
    int choice, data, pos;

    while (1) {
        printf("1. Insert at end\n2. Insert at beginning\n3. Insert at middle\n4. Delete a node\n5. Delete at position\n6. Traverse list\n7. Exit\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: \n");
                scanf("%d", &data);
                tail = insertEnd(tail, data);
                break;
            case 2:
                printf("Enter data to insert at beginning: \n");
                scanf("%d", &data);
                tail = insertBegin(tail, data);
                break;
            case 3:
                printf("Enter data to insert and position: \n");
                scanf("%d%d", &data, &pos);
                tail = insertMid(tail, data, pos);
                break;
            case 4:
                printf("Enter data to delete: \n");
                scanf("%d", &data);
                tail = deleteNode(tail, data);
                break;
            case 5:
                printf("Enter position to delete: \n");
                scanf("%d", &pos);
                tail = deleteAtMid(tail, pos);
                break;
            case 6:
                traverseList(tail);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
