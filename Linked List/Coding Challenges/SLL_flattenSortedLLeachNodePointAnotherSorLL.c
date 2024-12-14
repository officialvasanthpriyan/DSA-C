#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->child = mergeLists(a->child, b);
        return a;
    } else {
        b->child = mergeLists(a, b->child);
        return b;
    }
}

// Function to flatten the linked list
struct Node* flattenList(struct Node* head) {
    if (!head || !head->next) return head;

    // Recur for the next node and merge it with the current list
    head->next = flattenList(head->next);
    head = mergeLists(head, head->next);

    return head;
}

// Function to print the flattened linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->child;
    }
    printf("NULL\n");
}

// Function to create a linked list from user input
struct Node* createListFromUser() {
    int n, m, data;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter the number of main list nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for main list node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* mainNode = createNode(data);

        if (!head) {
            head = tail = mainNode;
        } else {
            tail->next = mainNode;
            tail = mainNode;
        }

        printf("Enter the number of child nodes for this node: ");
        scanf("%d", &m);

        struct Node* childHead = NULL, *childTail = NULL;

        for (int j = 0; j < m; j++) {
            printf("Enter data for child node %d: ", j + 1);
            scanf("%d", &data);
            struct Node* childNode = createNode(data);

            if (!childHead) {
                childHead = childTail = childNode;
            } else {
                childTail->child = childNode;
                childTail = childNode;
            }
        }
        mainNode->child = childHead;
    }

    return head;
}

int main() {
    struct Node* head = createListFromUser();

    printf("Flattening the linked list...\n");
    head = flattenList(head);

    printf("Flattened Linked List:\n");
    printList(head);

    return 0;
}
/*Enter the number of main list nodes: 3
Enter data for main list node 1: 5
Enter the number of child nodes for this node: 2
Enter data for child node 1: 7
Enter data for child node 2: 8
Enter data for main list node 2: 10
Enter the number of child nodes for this node: 1
Enter data for child node 1: 12
Enter data for main list node 3: 15
Enter the number of child nodes for this node: 2
Enter data for child node 1: 18
Enter data for child node 2: 20
Flattening the linked list...
Flattened Linked List:
5 -> 7 -> 8 -> 10 -> 12 -> 15 -> 18 -> 20 -> NULL*/