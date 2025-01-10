// Check if a given binary tree is a complete binary tree using a queue.
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the tree nodes
struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

// Define a structure for the queue nodes
struct QueueNode
{
    struct TreeNode *treeNode;
    struct QueueNode *next;
}*front = NULL, *rear = NULL;

// Function to create a new tree node
struct TreeNode* createTreeNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to enqueue a tree node
void enqueue(struct TreeNode *node)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue a tree node
struct TreeNode* dequeue()
{
    if(front == NULL)
        return NULL;

    struct QueueNode *temp = front;
    struct TreeNode *node = temp->treeNode;
    front = front->next;
    if(front == NULL)
        rear = NULL;

    free(temp);
    return node;
}

// Check if the queue is empty
int isQueueEmpty()
{
    return front == NULL;
}

// Function to check if the binary tree is complete
int isCompleteBinaryTree(struct TreeNode *root)
{
    if(root == NULL)
        return 1;

    enqueue(root);
    int flag = 0;

    while(!isQueueEmpty())
    {
        struct TreeNode *current = dequeue();

        if(current->left)
        {
            if(flag)
                return 0; // If a non-full node was encountered earlier, it's not complete
            enqueue(current->left);
        }
        else
        {
            flag = 1; // Mark that a non-full node was encountered
        }

        if(current->right)
        {
            if(flag)
                return 0; // If a non-full node was encountered earlier, it's not complete
            enqueue(current->right);
        }
        else
        {
            flag = 1; // Mark that a non-full node was encountered
        }
    }

    return 1;
}

// Function to build a binary tree dynamically
struct TreeNode* buildTree()
{
    struct TreeNode *root = NULL;
    int val;

    printf("Enter the root value (-1 for NULL): ");
    scanf("%d", &val);
    if(val == -1)
        return NULL;

    root = createTreeNode(val);
    enqueue(root);

    while(!isQueueEmpty())
    {
        struct TreeNode *current = dequeue();

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        if(val != -1)
        {
            current->left = createTreeNode(val);
            enqueue(current->left);
        }

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        if(val != -1)
        {
            current->right = createTreeNode(val);
            enqueue(current->right);
        }
    }

    return root;
}

int main()
{
    printf("Build the binary tree:\n");
    struct TreeNode *root = buildTree();

    if(isCompleteBinaryTree(root))
        printf("The binary tree is a complete binary tree.\n");
    else
        printf("The binary tree is NOT a complete binary tree.\n");

    return 0;
}
