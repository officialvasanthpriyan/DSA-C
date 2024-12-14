#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Find pairs whose sum equals a given value
void findPairs(struct Node* head, int target) {
    struct Node* start = head;
    struct Node* end = head;

    // Move end pointer to the last node
    while (end->next != NULL) {
        end = end->next;
    }

    int found = 0;

    // Two-pointer approach
    while (start != NULL && end != NULL && start != end && end->next != start) {
        int sum = start->data + end->data;

        if (sum == target) {
            printf("Pair found: (%d, %d)\n", start->data, end->data);
            found = 1;
            start = start->next; // Move start forward
            end = end->prev;     // Move end backward
        } else if (sum < target) {
            start = start->next; // Increase sum
        } else {
            end = end->prev;     // Decrease sum
        }
    }

    if (!found) {
        printf("No pairs found with sum %d.\n", target);
    }
}

// Traverse the list forward
void traverseForward(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, target;

    // printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Get user input for the list
    for (int i = 0; i < n; i++) {
        // printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    // printf("\nEnter the target sum: ");
    scanf("%d", &target);

    // printf("\nOriginal List:\n");
    traverseForward(head);

    // printf("\nPairs with sum %d:\n", target);
    findPairs(head, target);

    return 0;
}
