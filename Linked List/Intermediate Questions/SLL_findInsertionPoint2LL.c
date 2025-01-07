<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    // Get the lengths of both linked lists
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Calculate the difference in lengths
    int diff = abs(len1 - len2);

    // Move the pointer of the longer list forward by the difference
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            temp2 = temp2->next;
        }
    }

    // Traverse both lists simultaneously and check for intersection
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1; // Return the intersection point
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL; // No intersection
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Main function
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, data, position;

    // Input for the first linked list
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }

    // Input for the second linked list
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    // Create intersection if needed
    printf("Do you want to create an intersection between the two lists? (1 for yes, 0 for no): ");
    int createIntersection;
    scanf("%d", &createIntersection);
    if (createIntersection == 1) {
        printf("Enter the position in the first list to start the intersection (0-based index): ");
        scanf("%d", &position);
        
        // Find the intersection node in the first list
        struct Node* intersectionNode = head1;
        for (int i = 0; i < position; i++) {
            intersectionNode = intersectionNode->next;
        }

        // Attach the intersection node to the second list
        struct Node* temp = head2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = intersectionNode;
    }

    // Find intersection
    struct Node* intersectionNode = getIntersection(head1, head2);

    // Print the result
    if (intersectionNode != NULL) {
        printf("Intersection point is: %d\n", intersectionNode->data);
    } else {
        printf("No intersection point.\n");
    }

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    // Get the lengths of both linked lists
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Calculate the difference in lengths
    int diff = abs(len1 - len2);

    // Move the pointer of the longer list forward by the difference
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            temp2 = temp2->next;
        }
    }

    // Traverse both lists simultaneously and check for intersection
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2) {
            return temp1; // Return the intersection point
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL; // No intersection
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Main function
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, data, position;

    // Input for the first linked list
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head1, data);
    }

    // Input for the second linked list
    printf("Enter the number of nodes in the second linked list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head2, data);
    }

    // Create intersection if needed
    printf("Do you want to create an intersection between the two lists? (1 for yes, 0 for no): ");
    int createIntersection;
    scanf("%d", &createIntersection);
    if (createIntersection == 1) {
        printf("Enter the position in the first list to start the intersection (0-based index): ");
        scanf("%d", &position);
        
        // Find the intersection node in the first list
        struct Node* intersectionNode = head1;
        for (int i = 0; i < position; i++) {
            intersectionNode = intersectionNode->next;
        }

        // Attach the intersection node to the second list
        struct Node* temp = head2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = intersectionNode;
    }

    // Find intersection
    struct Node* intersectionNode = getIntersection(head1, head2);

    // Print the result
    if (intersectionNode != NULL) {
        printf("Intersection point is: %d\n", intersectionNode->data);
    } else {
        printf("No intersection point.\n");
    }

    return 0;
}
>>>>>>> 9763270258e2965099eef1696f1aad135b64dd5c
