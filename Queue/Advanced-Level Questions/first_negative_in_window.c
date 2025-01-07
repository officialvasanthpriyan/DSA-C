// Solve the "First Negative Integer in every Window of Size k" problem using a queue.
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Append function to add elements to the queue (linked list implementation)
void append(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        // To find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Remove front element from the queue
void remove_front() {
    if (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}
// Function to print the first negative integer in every window of size k
void first_negative_in_window(int arr[], int n, int k) {
    int queue[n]; // Queue to store indices of negative numbers
    int front = 0, rear = -1; 

    // Process the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            rear++;
            queue[rear] = i; 
        }
    }

    // Process remaining windows
    for (int i = k; i < n; i++) {
        // Print the first negative number in the previous window
        if (rear >= front) {
            printf("%d ", arr[queue[front]]);
        } else {
            printf("0 "); // No negative number in the window
        }

        // Remove elements that are out of the current window
        if (front <= rear && queue[front] <= i - k) {
            front++;
        }

        // Add the current element to the queue if it's negative
        if (arr[i] < 0) {
            rear++;
            queue[rear] = i;
        }
    }

    // Print the first negative number in the last window
    if (rear >= front) {
        printf("%d\n", arr[queue[front]]);
    } else {
        printf("0\n"); // No negative number in the window
    }
}

int main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the window size: ");
    scanf("%d", &k);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("First negative integer in every window of size %d:\n", k);
    first_negative_in_window(arr, n, k);

    return 0;
}