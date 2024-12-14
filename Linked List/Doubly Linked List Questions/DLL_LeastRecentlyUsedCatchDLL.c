#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the doubly linked list
struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
};

// LRU Cache structure
struct LRUCache {
    int capacity;
    int size;
    struct Node* head;
    struct Node* tail;
};

// Function to create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an LRU Cache
struct LRUCache* createCache(int capacity) {
    struct LRUCache* cache = (struct LRUCache*)malloc(sizeof(struct LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// Move a node to the front of the list
void moveToHead(struct LRUCache* cache, struct Node* node) {
    if (cache->head == node) return; // Already at the head

    // Remove the node from its current position
    if (node->prev) node->prev->next = node->next;
    if (node->next) node->next->prev = node->prev;

    if (cache->tail == node) cache->tail = node->prev;

    // Move the node to the front
    node->prev = NULL;
    node->next = cache->head;
    if (cache->head) cache->head->prev = node;
    cache->head = node;

    if (!cache->tail) cache->tail = node; // If the cache was empty
}

// Remove the least recently used node
void removeTail(struct LRUCache* cache) {
    if (!cache->tail) return;

    struct Node* toRemove = cache->tail;

    if (toRemove->prev) toRemove->prev->next = NULL;
    else cache->head = NULL;

    cache->tail = toRemove->prev;
    free(toRemove);
    cache->size--;
}

// Add a new key-value pair to the cache
void put(struct LRUCache* cache, int key, int value) {
    struct Node* current = cache->head;

    // Check if the key already exists
    while (current) {
        if (current->key == key) {
            current->value = value;
            moveToHead(cache, current);
            return;
        }
        current = current->next;
    }

    // If the key doesn't exist, create a new node
    struct Node* newNode = createNode(key, value);

    // If the cache is full, remove the least recently used item
    if (cache->size == cache->capacity) {
        removeTail(cache);
    }

    // Add the new node to the front
    newNode->next = cache->head;
    if (cache->head) cache->head->prev = newNode;
    cache->head = newNode;

    if (!cache->tail) cache->tail = newNode;

    cache->size++;
}

// Retrieve a value from the cache
int get(struct LRUCache* cache, int key) {
    struct Node* current = cache->head;

    // Search for the key in the list
    while (current) {
        if (current->key == key) {
            moveToHead(cache, current);
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;
}

// Display the current state of the cache
void displayCache(struct LRUCache* cache) {
    struct Node* current = cache->head;
    printf("Cache state: ");
    while (current) {
        printf("[%d:%d] ", current->key, current->value);
        current = current->next;
    }
    // printf("\n");
}

int main() {
    int capacity;
    printf("Enter the capacity of the LRU Cache: ");
    scanf("%d", &capacity);

    struct LRUCache* cache = createCache(capacity);
    int choice = 0;

    while (choice != 4) {
        printf("\n1. Put a key-value pair\n2. Get a value by key\n3. Display Cache\n4. Exit\nEnter your choice: \n");
        scanf("%d", &choice);

        if (choice == 1) {
            int key, value;
            printf("Enter key: \n");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            put(cache, key, value);
        } else if (choice == 2) {
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            int value = get(cache, key);
            if (value == -1) {
                printf("Key not found in cache.\n");
            } else {
                printf("Value for key %d: %d\n", key, value);
            }
        } else if (choice == 3) {
            displayCache(cache);
        } else if (choice == 4) {
            printf("Exiting...\n");
            
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
    }

    return 0;
}
