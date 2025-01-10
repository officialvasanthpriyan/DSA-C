// Solve the "Sliding Window Median" problem using a queue.
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head = NULL;

// Function to append a value to the queue
void append(int val)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to remove the first element (dequeue)
void dequeue()
{
    if(head == NULL)
        return;

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Function to display the current queue
void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to calculate the median of the current queue
float findMedian(int size)
{
    int values[size];
    int i = 0;
    struct Node *temp = head;

    while(temp != NULL)
    {
        values[i++] = temp->data;
        temp = temp->next;
    }

    // Sort the values to find the median
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(values[i] > values[j])
            {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    // Find median
    if(size % 2 == 0)
        return (values[size / 2 - 1] + values[size / 2]) / 2.0;
    else
        return values[size / 2];
}

int main()
{
    int k, val;

    printf("Enter the window size (k): ");
    scanf("%d", &k);

    printf("Enter the numbers (terminate with -1):\n");
    int count = 0;

    do
    {
        scanf("%d", &val);
        if(val != -1)
        {
            append(val);
            count++;

            // If the window size exceeds k, dequeue the first element
            if(count > k)
            {
                dequeue();
                count--;
            }

            // Print the median when the window is full
            if(count == k)
            {
                printf("Current window: ");
                display();
                printf("Median: %.2f\n", findMedian(k));
            }
        }
    } while(val != -1);

    return 0;
}
