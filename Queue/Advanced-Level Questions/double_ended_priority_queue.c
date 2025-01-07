// Implement a double-ended priority queue.
#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
}*head = NULL;

// Append a new value to the queue
void append(int val)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->next = NULL;
    // 3. Connection
    if(head == NULL) // First node connection
    {
        head = newnode;
    }
    else // Last node connection
    {
        struct Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Find and display the minimum value in the queue
int findMin()
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = head;
    int min = temp->data;
    while(temp != NULL)
    {
        if(temp->data < min)
            min = temp->data;
        temp = temp->next;
    }
    return min;
}

// Find and display the maximum value in the queue
int findMax()
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = head;
    int max = temp->data;
    while(temp != NULL)
    {
        if(temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

// Display the queue elements
void display()
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int val;
    printf("Enter queue elements (terminate with -1): ");
    do
    {
        scanf("%d", &val);
        if(val != -1)
            append(val);
    }while(val != -1);

    printf("Queue elements: ");
    display();

    int min = findMin();
    int max = findMax();

    printf("Minimum value in the queue: %d\n", min);
    printf("Maximum value in the queue: %d\n", max);

    return 0;
}
