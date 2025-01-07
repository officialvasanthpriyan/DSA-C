#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Function to merge k sorted linked lists
struct Node* mergeKLists(struct Node** lists, int k) {
    if (k == 0) return NULL;
    if (k == 1) return lists[0];

    // Repeatedly merge lists in pairs
    while (k > 1) {
        int i = 0;
        for (i = 0; i < k / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[k - i - 1]);
        }
        k = (k + 1) / 2;  // Reduce the number of lists by half
    }

    return lists[0];
}

// Function to create a linked list from user input
struct Node* createListFromUser() {
    int n, data;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the elements of the list in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    int k;

    // Get the number of linked lists
    printf("Enter the number of sorted linked lists (k): ");
    scanf("%d", &k);

    struct Node* lists[k];

    // Get each sorted linked list from the user
    for (int i = 0; i < k; i++) {
        printf("Enter sorted list %d:\n", i + 1);
        lists[i] = createListFromUser();
    }

    // Merge all k sorted linked lists
    struct Node* result = mergeKLists(lists, k);

    // Print the merged sorted list
    printf("Merged Sorted List:\n");
    printList(result);

    return 0;
}
/*Enter the number of sorted linked lists (k): 3
Enter sorted list 1:
Enter the number of elements in the list: 3
Enter the elements of the list in sorted order:
1 4 5
Enter sorted list 2:
Enter the number of elements in the list: 4
Enter the elements of the list in sorted order:
1 3 4 7
Enter sorted list 3:
Enter the number of elements in the list: 2
Enter the elements of the list in sorted order:
2 6
Merged Sorted List:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6 -> 7 -> NULL*/