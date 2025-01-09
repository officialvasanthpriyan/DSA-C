// Solve the "Gas Station" problem to find the starting point to complete a circular route.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int gas; // Gas available at the station
    int cost; // Cost to travel to the next station
    struct Node *next;
}*head = NULL;

void append(int gas, int cost)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->gas = gas;
    newnode->cost = cost;
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

void displayStations()
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        printf("No stations in the route\n");
        return;
    }
    printf("Stations (Gas, Cost):\n");
    while(temp != NULL)
    {
        printf("(%d, %d) ", temp->gas, temp->cost);
        temp = temp->next;
    }
    printf("\n");
}

int findStartingStation()
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        return -1; // No stations
    }

    int total_gas = 0, total_cost = 0, current_gas = 0, start = 0;
    int index = 0;

    // Traverse the queue
    while(temp != NULL)
    {
        total_gas += temp->gas;
        total_cost += temp->cost;

        current_gas += temp->gas - temp->cost;
        if(current_gas < 0)
        {
            // Cannot start from the current station, move start forward
            start = index + 1;
            current_gas = 0;
        }

        temp = temp->next;
        index++;
    }

    // If total gas is less than total cost, the trip is not possible
    if(total_gas < total_cost)
        return -1;

    return start;
}

int main()
{
    int gas, cost;
    printf("Enter gas and cost for each station (enter -1 -1 to stop):\n");
    do
    {
        scanf("%d %d", &gas, &cost);
        if(gas != -1 && cost != -1)
            append(gas, cost);
    }while(gas != -1 && cost != -1);

    displayStations();

    int startingStation = findStartingStation();
    if(startingStation != -1)
        printf("Start at station %d to complete the route.\n", startingStation);
    else
        printf("Not possible to complete the route.\n");

    return 0;
}
