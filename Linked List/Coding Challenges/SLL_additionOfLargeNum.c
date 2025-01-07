<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to append a node to the front of the linked list
void appendFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to create a linked list from a large number string
struct Node* createListFromString(char* number) {
    struct Node* head = NULL;
    for (int i = 0; number[i] != '\0'; i++) {
        appendFront(&head, number[i] - '0');
    }
    return head;
}

// Function to add two linked lists representing large numbers
struct Node* addLargeNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;

        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        appendFront(&result, sum % 10);
    }

    return result;
}

// Function to print a linked list in reverse order
void printListReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printListReverse(head->next);
    printf("%d", head->data);
}

// Function to free the linked list
void freeList(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char number1[1000], number2[1000];
    printf("Enter the first large number: ");
    scanf("%s", number1);
    printf("Enter the second large number: ");
    scanf("%s", number2);

    // Create linked lists for the numbers
    struct Node* num1 = createListFromString(number1);
    struct Node* num2 = createListFromString(number2);

    // Add the two numbers
    struct Node* result = addLargeNumbers(num1, num2);

    printf("\nThe sum of the two numbers is: ");
    printListReverse(result);
    printf("\n");

    // Free allocated memory
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to append a node to the front of the linked list
void appendFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to create a linked list from a large number string
struct Node* createListFromString(char* number) {
    struct Node* head = NULL;
    for (int i = 0; number[i] != '\0'; i++) {
        appendFront(&head, number[i] - '0');
    }
    return head;
}

// Function to add two linked lists representing large numbers
struct Node* addLargeNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int carry = 0;

    while (num1 || num2 || carry) {
        int sum = carry;

        if (num1) {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2) {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10;
        appendFront(&result, sum % 10);
    }

    return result;
}

// Function to print a linked list in reverse order
void printListReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printListReverse(head->next);
    printf("%d", head->data);
}

// Function to free the linked list
void freeList(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char number1[1000], number2[1000];
    printf("Enter the first large number: ");
    scanf("%s", number1);
    printf("Enter the second large number: ");
    scanf("%s", number2);

    // Create linked lists for the numbers
    struct Node* num1 = createListFromString(number1);
    struct Node* num2 = createListFromString(number2);

    // Add the two numbers
    struct Node* result = addLargeNumbers(num1, num2);

    printf("\nThe sum of the two numbers is: ");
    printListReverse(result);
    printf("\n");

    // Free allocated memory
    freeList(num1);
    freeList(num2);
    freeList(result);

    return 0;
}

>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
