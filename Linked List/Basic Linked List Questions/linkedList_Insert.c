#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head; // Point the new node to the current head
    head = newNode;       // Update the head pointer
    return head;
}

// Insert at the end
void insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node at the end
}

// Insert in the middle
void insertInMiddle(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);  // 50 null
    struct Node* temp = head; //1000
    int count = 1;

    // Traverse to the position just before the desired insertion point
    while (count < position - 1 && temp->next != NULL) { // 2<2 && true
        temp = temp->next; //2000
        count++; //2
    }

    // Insert the new node
    newNode->next = temp->next; //null<-3000 //50 3000
    temp->next = newNode; //5000    
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize an empty list
    int choice, value, position;

    // Insert some initial nodes to build a base list
    head = insertAtBeginning(head, 20); // First node
    head = insertAtBeginning(head, 10); // Insert at beginning
    insertAtEnd(head, 30);              // Insert at end

    printf("Initial list:\n");
    displayList(head);

    // Insert at the beginning
    printf("\nInsert at the beginning: ");
    printf("\nEnter value: ");
    scanf("%d", &value);
    head = insertAtBeginning(head, value);
    displayList(head);

    // Insert at the end
    printf("\nInsert at the end: ");
    printf("\nEnter value: ");
    scanf("%d", &value);
    insertAtEnd(head, value);
    displayList(head);

    // Insert in the middle
    printf("\nInsert in the middle: ");
    printf("\nEnter value: ");
    scanf("%d", &value); //10 20 30 40  3 50  // 10 20 50 30 40 //1000 50 3
    printf("Enter position: ");
    scanf("%d", &position);
    insertInMiddle(head, value, position);
    displayList(head);

    return 0;
}
