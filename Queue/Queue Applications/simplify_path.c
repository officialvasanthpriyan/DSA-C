// Use a queue to validate and simplify a file system path.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char folder[100]; // Folder name
    struct Node *next;
}*head = NULL;

void append(char *folder)
{
    // 1. Create memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    strcpy(newnode->folder, folder);
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
        printf("Simplified Path: /\n");
        return;
    }

    printf("Simplified Path: ");
    while(temp != NULL)
    {
        printf("/%s", temp->folder);
        temp = temp->next;
    }
    printf("\n");
}

void simplifyPath(char *path)
{
    char *token = strtok(path, "/");
    while(token != NULL)
    {
        if(strcmp(token, "..") == 0)
        {
            // Move up one directory
            if(head != NULL)
            {
                struct Node *temp = head;
                if(temp->next == NULL)
                {
                    // Only one node in the queue
                    free(temp);
                    head = NULL;
                }
                else
                {
                    // Traverse to the second last node
                    while(temp->next->next != NULL)
                    {
                        temp = temp->next;
                    }
                    free(temp->next);
                    temp->next = NULL;
                }
            }
        }
        else if(strcmp(token, ".") != 0 && strlen(token) > 0)
        {
            // Append valid folder names
            append(token);
        }
        token = strtok(NULL, "/");
    }
}

int main()
{
    char path[500];
    printf("Enter the file system path:\n");
    scanf("%s", path);

    simplifyPath(path);
    displayQueue();

    return 0;
}
