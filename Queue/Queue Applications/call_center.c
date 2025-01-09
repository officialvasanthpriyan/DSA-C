// Implement a call center simulation where customer calls are queued.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int callID; // Unique identifier for the call
    struct Node *next;
}*head = NULL;

void enqueue(int callID)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->callID = callID;
    newnode->next = NULL;

    // 3. Connection
    // Check for the first node connection (head to first node)
    if(head == NULL)
    {
        head = newnode;
    }
    // (last node to new node connection)
    else
    {
        struct Node *temp = head;
        // To find the last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void displayQueue()
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        printf("No calls in the queue\n");
        return;
    }
    while(temp != NULL)
    {
        printf("Call %d ", temp->callID);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int callID;
    printf("Enter call IDs (enter -1 to stop):\n");
    do
    {
        scanf("%d", &callID);
        if(callID != -1)
            enqueue(callID);
    }while(callID != -1);

    printf("Call queue:\n");
    displayQueue();
    return 0;
}
