// Find the maximum width of a binary tree using a queue.
#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Structure for queue node
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

struct QueueNode *front = NULL, *rear = NULL;

// Enqueue a tree node
void enqueue(struct TreeNode *node) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue a tree node
struct TreeNode *dequeue() {
    if (front == NULL) return NULL;

    struct QueueNode *temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;

    struct TreeNode *node = temp->node;
    free(temp);
    return node;
}

// Create a new tree node
struct TreeNode *createTreeNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build the binary tree from level order input
struct TreeNode *buildTreeFromLevelOrder(int arr[], int size) {
    if (size == 0) return NULL;

    struct TreeNode *root = createTreeNode(arr[0]);
    enqueue(root);
    int i = 1;

    while (front != NULL && i < size) {
        struct TreeNode *parent = dequeue();

        if (i < size && arr[i] != -1) {
            parent->left = createTreeNode(arr[i]);
            enqueue(parent->left);
        }
        i++;

        if (i < size && arr[i] != -1) {
            parent->right = createTreeNode(arr[i]);
            enqueue(parent->right);
        }
        i++;
    }

    return root;
}

// Calculate the maximum width of the binary tree
int maxWidth(struct TreeNode *root) {
    if (root == NULL) return 0;

    int maxWidth = 0;
    enqueue(root);
    int currentLevelNodes = 1;
    int nextLevelNodes = 0;

    while (front != NULL) {
        maxWidth = (maxWidth > currentLevelNodes) ? maxWidth : currentLevelNodes;

        struct TreeNode *node = dequeue();
        currentLevelNodes--;

        if (node->left) {
            enqueue(node->left);
            nextLevelNodes++;
        }

        if (node->right) {
            enqueue(node->right);
            nextLevelNodes++;
        }

        if (currentLevelNodes == 0) {
            currentLevelNodes = nextLevelNodes;
            nextLevelNodes = 0;
        }
    }

    return maxWidth;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, -1}; // Example input
    int size = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode *root = buildTreeFromLevelOrder(arr, size);
    int width = maxWidth(root);
    printf("Maximum width of the binary tree: %d\n", width);

    return 0;
}