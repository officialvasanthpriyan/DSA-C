// Implement a queue-based solution for level order traversal in a binary tree.
#include<stdio.h>
#include<stdlib.h>

// Tree node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue node structure
struct QueueNode
{
    struct Node *treeNode;
    struct QueueNode *next;
}*front = NULL, *rear = NULL;

// Function to enqueue a tree node into the queue
void enqueue(struct Node *treeNode)
{
    struct QueueNode *newnode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newnode->treeNode = treeNode;
    newnode->next = NULL;
    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Function to dequeue a tree node from the queue
struct Node* dequeue()
{
    if(front == NULL)
    {
        return NULL;
    }
    struct QueueNode *temp = front;
    struct Node *treeNode = temp->treeNode;
    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Check if the queue is empty
int isQueueEmpty()
{
    return front == NULL;
}

// Function to create a new tree node
struct Node* createTreeNode(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to construct a binary tree dynamically from user input
struct Node* buildTree()
{
    int val;
    printf("Enter the value for the root node (-1 for NULL): ");
    scanf("%d", &val);

    if(val == -1)
    {
        return NULL;
    }

    struct Node *root = createTreeNode(val);
    enqueue(root);

    while(!isQueueEmpty())
    {
        struct Node *current = dequeue();
        printf("Enter the left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        if(val != -1)
        {
            current->left = createTreeNode(val);
            enqueue(current->left);
        }

        printf("Enter the right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        if(val != -1)
        {
            current->right = createTreeNode(val);
            enqueue(current->right);
        }
    }

    return root;
}

// Function to perform level-order traversal of a binary tree
void levelOrderTraversal(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    enqueue(root);
    while(!isQueueEmpty())
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);
        if(current->left != NULL)
        {
            enqueue(current->left);
        }
        if(current->right != NULL)
        {
            enqueue(current->right);
        }
    }
    printf("\n");
}

int main()
{
    printf("Build the binary tree dynamically.\n");
    struct Node *root = buildTree();

    printf("Level-order traversal of the binary tree:\n");
    levelOrderTraversal(root);

    return 0;
}
