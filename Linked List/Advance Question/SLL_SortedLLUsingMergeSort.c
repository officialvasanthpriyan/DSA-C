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

// Function to split a linked list into two halves
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    // Move `fast` two steps and `slow` one step
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Split the list into two halves
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

// Function to sort a linked list using merge sort
struct Node* mergeSort(struct Node* head) {
    if (!head || !head->next) {
        return head; // Base case: if the list is empty or has a single node
    }

    struct Node* front = NULL;
    struct Node* back = NULL;

    // Split the list into two halves
    splitList(head, &front, &back);

    // Recursively sort each half
    front = mergeSort(front);
    back = mergeSort(back);

    // Merge the sorted halves
    return mergeSortedLists(front, back);
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
    int choice, data;

    while (1) {
        printf("\n1. Insert at end\n2. Traverse list\n3. Sort list\n4. Exit\nEnter your choice: ");
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
                head = mergeSort(head);
                printf("List sorted.\n");
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
