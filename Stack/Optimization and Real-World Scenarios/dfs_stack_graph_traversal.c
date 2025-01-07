<<<<<<< HEAD
// Use a stack to implement DFS for a graph traversal.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for stack
typedef struct {
    int* arr;   // Array to store stack elements
    int top;    // Index of the top element in the stack
    int size;   // Size of the stack
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Free the stack
void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

// Function to perform DFS using a stack
void dfs(int** graph, int vertices, int start) {
    Stack* stack = createStack(vertices);  // Stack for DFS
    bool* visited = (bool*)calloc(vertices, sizeof(bool));  // Visited array

    push(stack, start);
    visited[start] = true;

    printf("DFS Traversal: ");
    while (!isEmpty(stack)) {
        int node = pop(stack);
        printf("%d ", node);

        // Traverse all neighbors of the current node
        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                push(stack, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");

    freeStack(stack);
    free(visited);
}

int main() {
    int vertices, edges;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Dynamically allocate memory for the adjacency matrix
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }

    // Input the edges
    printf("Enter the edges (u v) where u and v are vertex indices (0-based):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // For undirected graph
    }

    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    // Perform DFS
    dfs(graph, vertices, start);

    // Free the allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
=======
// Use a stack to implement DFS for a graph traversal.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for stack
typedef struct {
    int* arr;   // Array to store stack elements
    int top;    // Index of the top element in the stack
    int size;   // Size of the stack
} Stack;

// Function to create a stack
Stack* createStack(int size) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = -1;
    stack->size = size;
    return stack;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->arr[stack->top--];
}

// Check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Free the stack
void freeStack(Stack* stack) {
    free(stack->arr);
    free(stack);
}

// Function to perform DFS using a stack
void dfs(int** graph, int vertices, int start) {
    Stack* stack = createStack(vertices);  // Stack for DFS
    bool* visited = (bool*)calloc(vertices, sizeof(bool));  // Visited array

    push(stack, start);
    visited[start] = true;

    printf("DFS Traversal: ");
    while (!isEmpty(stack)) {
        int node = pop(stack);
        printf("%d ", node);

        // Traverse all neighbors of the current node
        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                push(stack, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");

    freeStack(stack);
    free(visited);
}

int main() {
    int vertices, edges;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Dynamically allocate memory for the adjacency matrix
    int** graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int*)calloc(vertices, sizeof(int));
    }

    // Input the edges
    printf("Enter the edges (u v) where u and v are vertex indices (0-based):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // For undirected graph
    }

    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    // Perform DFS
    dfs(graph, vertices, start);

    // Free the allocated memory
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
