// Solve the "Sliding Window Maximum" problem using a queue.
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
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to find the maximum in the sliding window of size k
void sliding_window_maximum(int arr[], int n, int k) {
    // We will use an array to simulate the deque for simplicity
    int deque[100];
    int front = -1, rear = -1;

    // Loop through the array
    for (int i = 0; i < n; i++) {
        // Remove elements from the deque that are out of the current window
        if (front != -1 && deque[front] <= i - k) {
            front++;
        }

        // Remove elements from the deque while they are smaller than the current element
        while (front <= rear && arr[deque[rear]] <= arr[i]) {
            rear--;
        }

        // Add the current element index to the deque
        if (rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        deque[rear] = i;

        // If the window has formed, print the maximum element (arr[deque[front]])
        if (i >= k - 1) {
            printf("Max in window (%d-%d): %d\n", i - k + 1, i, arr[deque[front]]);
        }
    }
}

int main() {
    int val, k;
    printf("Enter the window size (k): ");
    scanf("%d", &k);
    int arr[100];
    int i = 0;

    printf("Enter elements of the array (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &val);
        if (val == -1) break;
        arr[i++] = val;
    }

    printf("Input array:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    sliding_window_maximum(arr, i, k);

    return 0;
}
