// Implement a blocking queue for multithreading.
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Node for the queue
struct Node {
    int data;
    struct Node *next;
} *head = NULL, *tail = NULL;

// Synchronization primitives
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_non_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_non_full = PTHREAD_COND_INITIALIZER;

int max_size = 5; // Maximum size of the queue
int current_size = 0;

// Append function to enqueue elements
void append(int val) {
    pthread_mutex_lock(&mutex);

    // Wait if the queue is full
    while (current_size >= max_size) {
        pthread_cond_wait(&cond_non_full, &mutex);
    }

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    current_size++;

    pthread_cond_signal(&cond_non_empty);
    pthread_mutex_unlock(&mutex);
}

// Remove function to dequeue elements
int remove_from_queue() {
    pthread_mutex_lock(&mutex);

    // Wait if the queue is empty
    while (current_size == 0) {
        pthread_cond_wait(&cond_non_empty, &mutex);
    }

    struct Node *temp = head;
    int data = temp->data;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
    current_size--;

    pthread_cond_signal(&cond_non_full);
    pthread_mutex_unlock(&mutex);

    return data;
}

// Display function
void display() {
    pthread_mutex_lock(&mutex);
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

// Producer function
void *producer(void *arg) {
    int *data = (int *)arg;
    for (int i = 0; i < 10; i++) {
        printf("Producer adding: %d\n", data[i]);
        append(data[i]);
        sleep(1); // Simulate work
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    for (int i = 0; i < 10; i++) {
        int value = remove_from_queue();
        printf("Consumer removed: %d\n", value);
        sleep(2); // Simulate work
    }
    return NULL;
}

int main() {
    int data[10];
    printf("Enter 10 elements for the queue:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &data[i]);
    }

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, (void *)data);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    printf("Final queue state: ");
    display();

    return 0;
}
