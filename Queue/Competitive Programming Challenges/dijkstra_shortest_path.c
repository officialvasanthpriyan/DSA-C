// Find the shortest path in a weighted graph using a priority queue (Dijkstra’s algorithm).
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node
{
    int vertex, weight;
    struct Node *next;
};

struct PriorityQueue
{
    int vertex, distance;
    struct PriorityQueue *next;
}*front = NULL;

// Function to add a new edge to the adjacency list
void addEdge(struct Node **adjList, int src, int dest, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to enqueue a vertex into the priority queue
void enqueue(int vertex, int distance)
{
    struct PriorityQueue *newNode = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    newNode->vertex = vertex;
    newNode->distance = distance;
    newNode->next = NULL;

    if(front == NULL || front->distance > distance)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        struct PriorityQueue *temp = front;
        while(temp->next != NULL && temp->next->distance <= distance)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to dequeue the minimum distance vertex
int dequeue()
{
    if(front == NULL)
        return -1;

    struct PriorityQueue *temp = front;
    int vertex = front->vertex;
    front = front->next;
    free(temp);
    return vertex;
}

// Check if the priority queue is empty
int isQueueEmpty()
{
    return front == NULL;
}

// Dijkstra's algorithm for shortest path
void dijkstra(struct Node **adjList, int vertices, int start)
{
    int distances[vertices];
    int visited[vertices];
    
    // Initialize distances and visited array
    for(int i = 0; i < vertices; i++)
    {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    
    // Start node distance is 0
    distances[start] = 0;
    enqueue(start, 0);
    
    while(!isQueueEmpty())
    {
        int current = dequeue();
        visited[current] = 1;

        struct Node *temp = adjList[current];
        while(temp != NULL)
        {
            int neighbor = temp->vertex;
            int weight = temp->weight;

            if(!visited[neighbor] && distances[current] + weight < distances[neighbor])
            {
                distances[neighbor] = distances[current] + weight;
                enqueue(neighbor, distances[neighbor]);
            }
            temp = temp->next;
        }
    }

    // Display shortest distances from the start vertex
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < vertices; i++)
    {
        printf("%d\t%d\n", i, distances[i]);
    }
}

int main()
{
    int vertices, edges, start;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    struct Node *adjList[vertices];
    for(int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("Enter the edges (src dest weight):\n");
    for(int i = 0; i < edges; i++)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(adjList, src, dest, weight);
        addEdge(adjList, dest, src, weight); // For undirected graph
    }

    printf("Enter the start vertex: ");
    scanf("%d", &start);

    dijkstra(adjList, vertices, start);

    return 0;
}
