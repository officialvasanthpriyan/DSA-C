#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Binary Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define the structure for a Doubly Linked List Node
struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

// Function to create a new TreeNode
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the binary tree
struct TreeNode* insertTreeNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }

    char direction;
    printf("Insert %d to the left or right of %d? (l/r): \n", data, root->data);
    scanf(" %c", &direction);

    if (direction == 'l' || direction == 'L') {
        root->left = insertTreeNode(root->left, data);
    } else if (direction == 'r' || direction == 'R') {
        root->right = insertTreeNode(root->right, data);
    } else {
        printf("Invalid input. Node not inserted.\n");
    }

    return root;
}

// Convert a binary tree to a doubly linked list
void treeToDLL(struct TreeNode* root, struct DLLNode** head, struct DLLNode** prev) {
    if (root == NULL) return;

    // Recursively process the left subtree
    treeToDLL(root->left, head, prev);

    // Create a new DLL node for the current tree node
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = root->data;
    newNode->prev = *prev;
    newNode->next = NULL;

    // Update the previous node's next pointer
    if (*prev) {
        (*prev)->next = newNode;
    } else {
        // If prev is NULL, this is the head of the DLL
        *head = newNode;
    }

    // Update the current node as the previous node for the next operation
    *prev = newNode;

    // Recursively process the right subtree
    treeToDLL(root->right, head, prev);
}

// Traverse and display the doubly linked list
void traverseDLL(struct DLLNode* head) {
    struct DLLNode* temp = head;
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct TreeNode* root = NULL;
    struct DLLNode* head = NULL;
    struct DLLNode* prev = NULL;

    int n, data;

    // Input the number of nodes in the binary tree
    printf("Enter the number of nodes in the binary tree: \n");
    scanf("%d", &n);

    // Input the values and construct the binary tree
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: \n", i + 1);
        scanf("%d", &data);
        if (root == NULL) {
            root = createTreeNode(data); // First node becomes the root
        } else {
            root = insertTreeNode(root, data); // Insert subsequent nodes
        }
    }

    // Convert the binary tree to a doubly linked list
    treeToDLL(root, &head, &prev);

    // Display the DLL
    printf("\nConverted Doubly Linked List:\n");
    traverseDLL(head);

    return 0;
}
