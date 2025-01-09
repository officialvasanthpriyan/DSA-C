// Use a queue to simulate a task scheduling system.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int taskID; // Task identifier
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int taskID)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->taskID = taskID;
    newnode->next = NULL;

    // 3. Connection
    // Check if the queue is empty
    if(front == NULL && rear == NULL)
    {
        front = rear = newnode; // First node in the queue
    }
    else
    {
        rear->next = newnode; // Add to the end of the queue
        rear = newnode; // Update the rear pointer
    }
}

void displayQueue()
{
    struct Node *temp = front;
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("Task %d ", temp->taskID);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int taskID;
    printf("Enter task IDs (enter -1 to stop):\n");
    do
    {
        scanf("%d", &taskID);
        if(taskID != -1)
            enqueue(taskID);
    }while(taskID != -1);

    printf("Scheduled tasks:\n");
    displayQueue();
    return 0;
}
