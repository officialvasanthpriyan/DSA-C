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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2; // If the first list is empty, return the second list
    if (l2 == NULL) return l1; // If the second list is empty, return the first list

    struct Node* mergedHead = NULL; // Head of the merged list
    struct Node* current = NULL;    // To traverse and build the merged list

    // Initialize the merged list
    if (l1->data < l2->data) {
        mergedHead = l1;
        l1 = l1->next;
    } else {
        mergedHead = l2;
        l2 = l2->next;
    }
    current = mergedHead;

    // Traverse and merge the lists
    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // Attach remaining nodes from the non-empty list
    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return mergedHead;
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
    // Creating first sorted list: 1 -> 3 -> 5
    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Creating second sorted list: 2 -> 4 -> 6
    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    // Merge the lists
    struct Node* mergedList = mergeSortedLists(l1, l2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
