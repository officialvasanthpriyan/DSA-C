// Implement a double-ended queue (Deque).
#include <stdio.h>
#define SIZE 5  // Maximum size of the deque

int deque[SIZE];
int front = -1, rear = -1;

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element at the front
void insertFront(int element) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at the front.\n", element);
        return;
    }
    if (isEmpty()) {  // If deque is empty
        front = rear = 0;
    } else if (front == 0) {  // Wrap around to the end
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = element;
    printf("Inserted %d at the front.\n", element);
}

// Function to insert an element at the rear
void insertRear(int element) {
    if (isFull()) {
        printf("Deque is full. Cannot insert %d at the rear.\n", element);
        return;
    }
    if (isEmpty()) {  // If deque is empty
        front = rear = 0;
    } else if (rear == SIZE - 1) {  // Wrap around to the beginning
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = element;
    printf("Inserted %d at the rear.\n", element);
}

// Function to delete an element from the front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }
    printf("Deleted %d from the front.\n", deque[front]);
    if (front == rear) {  // Deque becomes empty
        front = rear = -1;
    } else if (front == SIZE - 1) {  // Wrap around to the beginning
        front = 0;
    } else {
        front++;
    }
}

// Function to delete an element from the rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return;
    }
    printf("Deleted %d from the rear.\n", deque[rear]);
    if (front == rear) {  // Deque becomes empty
        front = rear = -1;
    } else if (rear == 0) {  // Wrap around to the end
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

// Function to display the elements of the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nDouble-Ended Queue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter the value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
