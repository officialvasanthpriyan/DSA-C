// Find the span of stock prices for n days using a queue (Stock Span Problem).
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

void append(int val) {
    // 1. Create a memory for the node
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    // 2. Initialize the node memory
    newnode->data = val;
    newnode->next = NULL;
    // 3. Connection
    // Check for first node connection (head to first node)
    if (head == NULL) {
        head = newnode;
    } else {
        struct Node *temp = head;
        // To find last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void calculateStockSpan() {
    if (head == NULL) {
        printf("No stock prices to calculate span.\n");
        return;
    }

    struct Node *temp = head;
    int index = 0;

    printf("Stock Spans: ");
    while (temp != NULL) {
        int span = 1;  // Default span is 1
        struct Node *prev = head;
        int count = 0;

        // Traverse the list to find the span
        while (prev != temp) {
            if (prev->data <= temp->data) {
                span++;
            } else {
                span = 1;
            }
            prev = prev->next;
            count++;
        }

        printf("%d ", span);
        temp = temp->next;
        index++;
    }
    printf("\n");
}

int main() {
    int val;

    printf("Enter stock prices for n days (-1 to stop):\n");
    do {
        scanf("%d", &val);
        if (val != -1) {
            append(val);
        }
    } while (val != -1);

    printf("Stock Prices: ");
    display();

    calculateStockSpan();

    return 0;
}
