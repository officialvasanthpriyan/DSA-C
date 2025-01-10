// Solve the "Number of Islands" problem using BFS with a queue.
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

// Directions for exploring neighbors (up, down, left, right, and diagonals)
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

// Queue node structure
struct Node
{
    int x, y;
    struct Node *next;
}*front = NULL, *rear = NULL;

// Function to enqueue a coordinate
void enqueue(int x, int y)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->x = x;
    newnode->y = y;
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

// Function to dequeue a coordinate
struct Node* dequeue()
{
    if(front == NULL)
        return NULL;

    struct Node *temp = front;
    front = front->next;
    if(front == NULL)
        rear = NULL;

    return temp;
}

// Check if the queue is empty
int isQueueEmpty()
{
    return front == NULL;
}

// BFS to explore the island
void bfs(int grid[MAX][MAX], int visited[MAX][MAX], int rows, int cols, int startX, int startY)
{
    enqueue(startX, startY);
    visited[startX][startY] = 1;

    while(!isQueueEmpty())
    {
        struct Node *current = dequeue();
        int x = current->x;
        int y = current->y;
        free(current);

        // Explore all 8 neighbors
        for(int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && 
               grid[newX][newY] == 1 && visited[newX][newY] == 0)
            {
                enqueue(newX, newY);
                visited[newX][newY] = 1; // Mark as visited immediately after enqueueing
            }
        }
    }
}

// Function to count the number of islands
int countIslands(int grid[MAX][MAX], int rows, int cols)
{
    int visited[MAX][MAX] = {0};
    int islandCount = 0;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == 0)
            {
                bfs(grid, visited, rows, cols, i, j);
                islandCount++;
            }
        }
    }

    return islandCount;
}

int main()
{
    int rows, cols;
    int grid[MAX][MAX];

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the grid values (0 for water, 1 for land):\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = countIslands(grid, rows, cols);
    printf("Number of islands: %d\n", result);

    return 0;
}
