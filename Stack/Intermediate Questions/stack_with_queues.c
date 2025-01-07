// Implement a stack using two queues.
#include <stdio.h>
#include <stdlib.h>

// Structure for a queue
typedef struct Queue {
    int *arr;
    int front, rear, size, capacity;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is empty
int isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFullQueue(Queue* queue) {
    return queue->size == queue->capacity;
}

// Enqueue operation
void enqueue(Queue* queue, int value) {
    if (isFullQueue(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
    queue->size++;
}

// Dequeue operation
int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// Peek front element
int front(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Stack structure using two queues
typedef struct Stack {
    Queue* queue1;
    Queue* queue2;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue1 = createQueue(capacity);
    stack->queue2 = createQueue(capacity);
    stack->capacity = capacity;
    return stack;
}

// Push operation
void push(Stack* stack, int value) {
    if (isFullQueue(stack->queue1)) {
        printf("Stack overflow!\n");
        return;
    }

    enqueue(stack->queue1, value);
    printf("Pushed %d\n", value);
}

// Pop operation
int pop(Stack* stack) {
    if (isEmptyQueue(stack->queue1)) {
        printf("Stack underflow!\n");
        return -1;
    }

    // Transfer elements from queue1 to queue2 except the last one
    while (stack->queue1->size > 1) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }

    // The last element of queue1 is the stack's top element
    int poppedValue = dequeue(stack->queue1);

    // Swap the queues
    Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;

    printf("Popped %d\n", poppedValue);
    return poppedValue;
}

// Peek the top element
int top(Stack* stack) {
    if (isEmptyQueue(stack->queue1)) {
        printf("Stack is empty!\n");
        return -1;
    }

    // Transfer elements from queue1 to queue2 except the last one
    while (stack->queue1->size > 1) {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }

    // The last element of queue1 is the stack's top element
    int topValue = front(stack->queue1);

    // Move it to queue2
    enqueue(stack->queue2, dequeue(stack->queue1));

    // Swap the queues back
    Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;

    return topValue;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return isEmptyQueue(stack->queue1);
}

// Driver code to test the stack
int main() {
    Stack* stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", top(stack));

    pop(stack);

    printf("Top element: %d\n", top(stack));

    pop(stack);
    pop(stack);

    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    return 0;
}
