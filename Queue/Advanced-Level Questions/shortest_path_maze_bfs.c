// Find the shortest path in a maze using a queue and BFS (Breadth-First Search).
#include<stdio.h>
#include<stdlib.h>

// Node for the queue
struct Node {
    int x, y, dist;
    struct Node* next;
} *front = NULL, *rear = NULL;

// Dimensions of the maze
int maze[100][100], visited[100][100];
int rows, cols;

// Direction vectors for moving up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Append to the queue
void enqueue(int x, int y, int dist) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->x = x;
    newnode->y = y;
    newnode->dist = dist;
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue from the queue
struct Node* dequeue() {
    if (front == NULL) return NULL;

    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;

    return temp;
}

// Check if the cell is valid
int isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1 && !visited[x][y]);
}

// BFS to find the shortest path
int bfs(int startX, int startY, int endX, int endY) {
    enqueue(startX, startY, 0);
    visited[startX][startY] = 1;

    while (front != NULL) {
        struct Node* current = dequeue();
        int x = current->x, y = current->y, dist = current->dist;
        free(current);

        // If we reach the destination, return the distance
        if (x == endX && y == endY) {
            return dist;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY)) {
                enqueue(newX, newY, dist + 1);
                visited[newX][newY] = 1;
            }
        }
    }

    return -1; // No path found
}

// Display the maze
void displayMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of rows and columns of the maze:\n");
    scanf("%d %d", &rows, &cols);

    printf("Enter the maze (1 for path, 0 for wall):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;
        }
    }

    int startX, startY, endX, endY;
    printf("Enter the starting position (x y):\n");
    scanf("%d %d", &startX, &startY);
    printf("Enter the ending position (x y):\n");
    scanf("%d %d", &endX, &endY);

    printf("Maze:\n");
    displayMaze();

    int shortestPath = bfs(startX, startY, endX, endY);
    if (shortestPath != -1) {
        printf("Shortest path length: %d\n", shortestPath);
    } else {
        printf("No path found.\n");
    }

    return 0;
}
