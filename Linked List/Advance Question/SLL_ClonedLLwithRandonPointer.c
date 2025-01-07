#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list with random pointers
struct Node {
    int data;
    struct Node* next;
    struct Node* random; // Random pointer
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("Data: %d, Random: %d\n", current->data, 
               current->random ? current->random->data : -1);
        current = current->next;
    }
    printf("\n");
}

// Function to clone a linked list with random pointers
struct Node* cloneList(struct Node* head) {
    if (!head) {
        return NULL;
    }

    struct Node* current = head;

    // Step 1: Insert cloned nodes between original nodes
    while (current) {
        struct Node* clone = createNode(current->data);
        clone->next = current->next;
        current->next = clone;
        current = clone->next;
    }

    // Step 2: Set random pointers for the cloned nodes
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // Step 3: Separate the original and cloned lists
    struct Node* clonedHead = head->next;
    struct Node* temp;
    current = head;

    while (current) {
        temp = current->next;
        current->next = temp->next;
        if (temp->next) {
            temp->next = temp->next->next;
        }
        current = current->next;
    }

    return clonedHead;
}

// Function to create a linked list with user input
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        nodes[i] = newNode;
    }

    for (int i = 0; i < n; i++) {
        int randomIndex;
        printf("Enter the index of the random pointer for node %d (0-based, -1 for NULL): ", i + 1);
        scanf("%d", &randomIndex);

        if (randomIndex >= 0 && randomIndex < n) {
            nodes[i]->random = nodes[randomIndex];
        } else {
            nodes[i]->random = NULL;
        }
    }

    free(nodes);
    return head;
}

int main() {
    printf("Create the linked list:\n");
    struct Node* head = createLinkedList();

    printf("\nOriginal List:\n");
    printList(head);

    struct Node* clonedHead = cloneList(head);

    printf("\nCloned List:\n");
    printList(clonedHead);

    return 0;
}
