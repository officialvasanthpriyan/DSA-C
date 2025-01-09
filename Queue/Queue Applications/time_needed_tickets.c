// Use a queue to validate and simplify a file system path.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int tickets;
    struct Node *next;
}*head = NULL;

void append(int val)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->tickets = val;
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

void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->tickets);
        temp = temp->next;
    }
    printf("\n");
}

int timeToBuyTickets(int position)
{
    struct Node *temp = head;
    int time = 0, index = 0;

    while(head != NULL)
    {
        // Decrement ticket count for the person at the head of the queue
        head->tickets -= 1;
        time++;

        if(head->tickets == 0)
        {
            // Remove the person from the queue
            struct Node *toDelete = head;
            head = head->next;
            free(toDelete);
        }
        else
        {
            // Move the person to the back of the queue
            if(head != NULL)
            {
                struct Node *toMove = head;
                head = head->next;
                toMove->next = NULL;

                if(head == NULL)
                {
                    head = toMove;
                }
                else
                {
                    struct Node *end = head;
                    while(end->next != NULL)
                    {
                        end = end->next;
                    }
                    end->next = toMove;
                }
            }
        }

        // Check if the position has been processed
        if(index == position && head == NULL)
        {
            break;
        }
        if(index == position)
        {
            index = -1; // Reset index tracking
        }
        else if(index == -1)
        {
            index = position;
        }
    }

    return time;
}

int main()
{
    int tickets, position, val;
    printf("Enter the number of tickets for each person (-1 to stop):\n");
    int index = 0;

    do
    {
        scanf("%d", &val);
        if(val != -1)
        {
            append(val);
            index++;
        }
    } while(val != -1);

    printf("Enter the position of the person (0-based index):\n");
    scanf("%d", &position);

    int time = timeToBuyTickets(position);
    printf("Time needed for position %d to buy tickets: %d\n", position, time);

    return 0;
}
