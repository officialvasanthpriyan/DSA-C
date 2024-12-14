#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct ListNode {
    int data;
    struct ListNode* next;
};

// Node structure for the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new list node
struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append to the linked list
void appendToList(struct ListNode** head, int data) {
    struct ListNode* newNode = createListNode(data);
    if (!(*head)) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the middle node of a linked list
struct ListNode* findMiddle(struct ListNode* head, struct ListNode** prev) {
    struct ListNode *slow = head, *fast = head;
    *prev = NULL;

    while (fast && fast->next) {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to convert a sorted linked list to a balanced BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (!head) {
        return NULL; // Base case
    }

    struct ListNode* prev = NULL;
    struct ListNode* mid = findMiddle(head, &prev);

    // The middle element becomes the root
    struct TreeNode* root = createTreeNode(mid->data);

    // If there's only one element, return as the leaf node
    if (!prev) {
        return root;
    }

    // Disconnect the left part of the list
    prev->next = NULL;

    // Recursively construct the left and right subtrees
    root->left = sortedListToBST(head); // Left half
    root->right = sortedListToBST(mid->next); // Right half

    return root;
}

// Function to perform in-order traversal of a BST
void inorderTraversal(struct TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;
    int n, data;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the sorted linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendToList(&head, data);
    }

    printf("Original Linked List:\n");
    printList(head);

    struct TreeNode* root = sortedListToBST(head);

    printf("In-order traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
