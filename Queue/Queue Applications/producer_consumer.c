#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int item; // Item produced or consumed
    struct Node *next;
}*head = NULL;

void produce(int item)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->item = item;
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
    printf("Produced: %d\n", item);
}

void consume()
{
    if(head == NULL)
    {
        printf("Queue is empty, no items to consume.\n");
        return;
    }
    // Consume the first item in the queue
    struct Node *temp = head;
    printf("Consumed: %d\n", temp->item);
    head = head->next;
    free(temp);
}

void displayQueue()
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue: ");
    while(temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, item;
    printf("1. Produce item\n2. Consume item\n3. Display queue\n4. Exit\n");

    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                produce(item);
                break;
            case 2:
                consume();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    }while(choice != 4);

    return 0;
}
