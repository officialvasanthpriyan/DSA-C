// Design an LRU cache using a stack and a hash map.
#include <stdio.h>
#include <stdlib.h>

// Structure for the doubly linked list node
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// HashMap structure (for storing keys and pointers to nodes)
#define MAP_SIZE 1000
typedef struct HashMap {
    Node* map[MAP_SIZE];  // Array of Node pointers
} HashMap;

// LRUCache structure that includes a doubly linked list and hash map
typedef struct LRUCache {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    HashMap* map;
} LRUCache;

// Hash function for the hash map
int hash(int key) {
    return key % MAP_SIZE;
}

// Create a new cache
LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = (Node*)malloc(sizeof(Node));  // Dummy head
    cache->tail = (Node*)malloc(sizeof(Node));  // Dummy tail
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;

    cache->map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < MAP_SIZE; i++) {
        cache->map->map[i] = NULL;
    }

    return cache;
}

// Remove a node from the list
void removeNode(LRUCache* cache, Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

// Add a node to the front of the list
void addNodeToHead(LRUCache* cache, Node* node) {
    node->next = cache->head->next;
    cache->head->next->prev = node;
    cache->head->next = node;
    node->prev = cache->head;
}

// Move a node to the front of the list (to indicate recent usage)
void moveToHead(LRUCache* cache, Node* node) {
    removeNode(cache, node);
    addNodeToHead(cache, node);
}

// Get an item from the cache
int get(LRUCache* cache, int key) {
    int index = hash(key);
    Node* node = cache->map->map[index];
    if (node == NULL) {
        return -1;
    }
    moveToHead(cache, node);
    return node->value;
}

// Put an item into the cache
void put(LRUCache* cache, int key, int value) {
    int index = hash(key);
    Node* node = cache->map->map[index];

    // If the node exists, update its value and move it to the head
    if (node != NULL) {
        node->value = value;
        moveToHead(cache, node);
    } else {
        // Create a new node
        node = (Node*)malloc(sizeof(Node));
        node->key = key;
        node->value = value;
        addNodeToHead(cache, node);
        cache->size++;

        // Insert the node in the hash map
        cache->map->map[index] = node;

        // If the cache exceeds the capacity, evict the least recently used item
        if (cache->size > cache->capacity) {
            Node* tail = cache->tail->prev;
            removeNode(cache, tail);
            cache->map->map[hash(tail->key)] = NULL;
            free(tail);
            cache->size--;
        }
    }
}

int main() {
    LRUCache* cache = createCache(2);

    put(cache, 1, 1);
    put(cache, 2, 2);
    printf("Get 1: %d\n", get(cache, 1));       // returns 1
    put(cache, 3, 3);                          // evicts key 2
    printf("Get 2: %d\n", get(cache, 2));       // returns -1 (not found)
    put(cache, 4, 4);                          // evicts key 1
    printf("Get 1: %d\n", get(cache, 1));       // returns -1 (not found)
    printf("Get 3: %d\n", get(cache, 3));       // returns 3
    printf("Get 4: %d\n", get(cache, 4));       // returns 4

    return 0;
}
