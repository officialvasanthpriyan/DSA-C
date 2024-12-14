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

// Function to count the nodes in the linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to split the linked list into k parts
struct Node** splitListToParts(struct Node* head, int k) {
    int length = getLength(head);
    int partSize = length / k;
    int remainder = length % k;

    struct Node** parts = (struct Node**)malloc(k * sizeof(struct Node*));
    struct Node* current = head;

    for (int i = 0; i < k; i++) {
        parts[i] = current;
        int currentPartSize = partSize + (i < remainder ? 1 : 0);
        for (int j = 1; j < currentPartSize && current; j++) {
            current = current->next;
        }
        if (current) {
            struct Node* nextPart = current->next;
            current->next = NULL;
            current = nextPart;
        }
    }

    return parts;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to create a linked list from user input
void createListFromUser(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        appendNode(head, data);
    }
}

int main() {
    struct Node* head = NULL;
    int k;

    // Create the linked list
    printf("Create the linked list:\n");
    createListFromUser(&head);

    // Get the number of parts
    printf("Enter the number of parts to split the list into: ");
    scanf("%d", &k);

    // Split the list
    struct Node** parts = splitListToParts(head, k);

    // Print the resulting parts
    printf("\nThe linked list split into %d parts:\n", k);
    for (int i = 0; i < k; i++) {
        printf("Part %d: ", i + 1);
        printList(parts[i]);
    }

    free(parts);
    return 0;
}
