#include <stdio.h>
#include <stdlib.h>

// Node structure for the multilevel doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    struct Node* child; // Pointer to the child doubly linked list
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to append a node to the end of a doubly linked list
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
    newNode->prev = current;
}

// Function to flatten the multilevel doubly linked list
struct Node* flatten(struct Node* head) {
    if (!head) {
        return NULL;
    }

    struct Node* current = head;

    while (current) {
        // If the current node has a child
        if (current->child) {
            struct Node* child = current->child;
            struct Node* next = current->next;

            // Attach the child to the current node's next
            current->next = child;
            child->prev = current;

            // Flatten the child list recursively
            struct Node* tail = flatten(child);

            // If there was a next node, attach it to the end of the flattened child list
            if (next) {
                tail->next = next;
                next->prev = tail;
            }

            // Nullify the child pointer
            current->child = NULL;
        }
        current = current->next;
    }
    return head;
}

// Function to print a doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to create a multilevel doubly linked list with user input
void createMultilevelList(struct Node** head) {
    int n, data, hasChild;
    struct Node* current = NULL;

    printf("Enter the number of nodes in the main list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        appendNode(head, data);
    }

    current = *head;
    while (current) {
        printf("Does node %d have a child list? (1 for Yes, 0 for No): ", current->data);
        scanf("%d", &hasChild);

        if (hasChild) {
            printf("Creating child list for node %d:\n", current->data);
            createMultilevelList(&(current->child));
        }

        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    printf("Create the multilevel doubly linked list:\n");
    createMultilevelList(&head);

    printf("\nOriginal multilevel list (only main list displayed):\n");
    printList(head);

    head = flatten(head);

    printf("\nFlattened list:\n");
    printList(head);

    return 0;
}
