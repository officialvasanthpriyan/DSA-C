// Implement an LRU cache using a queue and hash map.
#include<stdio.h>
#include<stdlib.h>

// Node for the doubly linked list
struct Node {
    int key;
    struct Node* prev;
    struct Node* next;
} *head = NULL, *tail = NULL;

// Hash map to store key and corresponding node
#define HASH_SIZE 100
struct Node* hashMap[HASH_SIZE];

// Initialize the hash map
void initHashMap() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashMap[i] = NULL;
    }
}

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to remove a node from the doubly linked list
void removeNode(struct Node* node) {
    if (node == head) {
        head = head->next;
        if (head) head->prev = NULL;
    } else if (node == tail) {
        tail = tail->prev;
        if (tail) tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
}

// Function to move a node to the front (head) of the doubly linked list
void moveToHead(struct Node* node) {
    if (node == head) return;

    removeNode(node);

    node->next = head;
    node->prev = NULL;
    if (head) head->prev = node;
    head = node;

    if (tail == NULL) {
        tail = head;
    }
}

// Function to add a node to the front (head) of the doubly linked list
void addToHead(struct Node* node) {
    node->next = head;
    node->prev = NULL;
    if (head) head->prev = node;
    head = node;

    if (tail == NULL) {
        tail = head;
    }
}

// Function to remove the least recently used (LRU) node
void removeTail() {
    if (tail) {
        struct Node* temp = tail;
        if (tail == head) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        hashMap[temp->key % HASH_SIZE] = NULL;
        free(temp);
    }
}

// LRU Cache implementation
void lruCache(int key, int capacity) {
    int hashIndex = key % HASH_SIZE;

    if (hashMap[hashIndex] != NULL && hashMap[hashIndex]->key == key) {
        // If key exists in cache, move it to the front
        moveToHead(hashMap[hashIndex]);
    } else {
        // If key does not exist, add it to the cache
        struct Node* newNode = createNode(key);
        hashMap[hashIndex] = newNode;

        // Add the new node to the front
        addToHead(newNode);

        // Check if capacity exceeded, remove LRU node
        int count = 0;
        struct Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        if (count > capacity) {
            removeTail();
        }
    }
}

// Function to find the maximum in the LRU cache
int findMax() {
    int max = -99999;
    struct Node* temp = head;
    while (temp) {
        if (temp->key > max) max = temp->key;
        temp = temp->next;
    }
    return max;
}

// Function to find the minimum in the LRU cache
int findMin() {
    int min = 99999;
    struct Node* temp = head;
    while (temp) {
        if (temp->key < min) min = temp->key;
        temp = temp->next;
    }
    return min;
}

// Display the current LRU cache
void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int capacity;
    printf("Enter the capacity of the LRU cache: ");
    scanf("%d", &capacity);

    int val;
    printf("Enter elements of the array (enter -1 to stop):\n");
    initHashMap(); // Initialize hash map

    while (1) {
        scanf("%d", &val);
        if (val == -1) break;
        lruCache(val, capacity);
    }

    printf("Current LRU Cache:\n");
    display();

    printf("Maximum in LRU Cache: %d\n", findMax());
    printf("Minimum in LRU Cache: %d\n", findMin());

    return 0;
}
