<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // A list with 0 or 1 node is a palindrome
    }

    // Find the middle of the list
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf; // To restore the list later

    // Compare the two halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            reverseList(temp); // Restore the list before returning
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverseList(temp); // Restore the list
    return true;
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
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Check if it's a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Print the restored list
    printf("Restored List: ");
    printList(head);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // A list with 0 or 1 node is a palindrome
    }

    // Find the middle of the list
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;
    struct Node* temp = secondHalf; // To restore the list later

    // Compare the two halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            reverseList(temp); // Restore the list before returning
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverseList(temp); // Restore the list
    return true;
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
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Check if it's a palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Print the restored list
    printf("Restored List: ");
    printList(head);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
