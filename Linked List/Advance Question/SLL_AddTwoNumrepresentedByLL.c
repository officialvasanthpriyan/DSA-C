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

// Function to append a node to the end of a linked list
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

// Function to add two numbers represented by linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummyHead = createNode(0);
    struct Node* p = l1, *q = l2, *current = dummyHead;
    int carry = 0;

    while (p || q) {
        int x = (p) ? p->data : 0;
        int y = (q) ? q->data : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = createNode(sum % 10);
        current = current->next;
        if (p) p = p->next;
        if (q) q = q->next;
    }

    if (carry > 0) {
        current->next = createNode(carry);
    }

    struct Node* result = dummyHead->next;
    free(dummyHead);
    return result;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a linked list from user input
void createListFromUser(struct Node** head) {
    int n, data;
    printf("Enter the number of digits: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter digit %d: ", i + 1);
        scanf("%d", &data);
        appendNode(head, data);
    }
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    printf("Create the first number:\n");
    createListFromUser(&l1);

    printf("Create the second number:\n");
    createListFromUser(&l2);

    printf("First Number: ");
    printList(l1);

    printf("Second Number: ");
    printList(l2);

    struct Node* result = addTwoNumbers(l1, l2);

    printf("Sum: ");
    printList(result);

    return 0;
}
