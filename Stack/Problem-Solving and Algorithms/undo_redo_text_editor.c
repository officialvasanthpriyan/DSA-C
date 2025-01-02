// Implement an undo/redo feature using stacks.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the stack
typedef struct {
    char* action;
    struct ActionStack* next;
} ActionStack;

// Function to create a new stack node
ActionStack* createStackNode(char* action) {
    ActionStack* newNode = (ActionStack*)malloc(sizeof(ActionStack));
    newNode->action = strdup(action);  // Copy the action
    newNode->next = NULL;
    return newNode;
}

// Push an action to the stack
void push(ActionStack** top, char* action) {
    ActionStack* newNode = createStackNode(action);
    newNode->next = *top;
    *top = newNode;
}

// Pop an action from the stack
char* pop(ActionStack** top) {
    if (*top == NULL) {
        return NULL;  // Stack is empty
    }
    ActionStack* temp = *top;
    *top = (*top)->next;
    char* action = temp->action;
    free(temp);
    return action;
}

// Function to undo an action
void undo(ActionStack** undoStack, ActionStack** redoStack) {
    char* action = pop(undoStack);
    if (action) {
        printf("Undo: %s\n", action);
        push(redoStack, action);  // Push the action to redo stack
    } else {
        printf("Nothing to undo.\n");
    }
}

// Function to redo an action
void redo(ActionStack** undoStack, ActionStack** redoStack) {
    char* action = pop(redoStack);
    if (action) {
        printf("Redo: %s\n", action);
        push(undoStack, action);  // Push the action back to undo stack
    } else {
        printf("Nothing to redo.\n");
    }
}

// Function to simulate adding a new action (text change)
void addAction(ActionStack** undoStack, ActionStack** redoStack, char* action) {
    push(undoStack, action);  // Add the action to the undo stack
    // Clear the redo stack when a new action is performed
    while (*redoStack) {
        free(pop(redoStack));  // Free all elements in redo stack
    }
    printf("Action added: %s\n", action);
}

int main() {
    ActionStack* undoStack = NULL;  // Stack for undo actions
    ActionStack* redoStack = NULL;  // Stack for redo actions

    // Simulate adding actions
    addAction(&undoStack, &redoStack, "Typed 'Hello'");
    addAction(&undoStack, &redoStack, "Typed 'World'");
    addAction(&undoStack, &redoStack, "Deleted 'World'");

    // Perform undo and redo actions
    undo(&undoStack, &redoStack);  // Undo last action (delete 'World')
    redo(&undoStack, &redoStack);  // Redo last undone action (delete 'World')
    undo(&undoStack, &redoStack);  // Undo last action (type 'World')
    undo(&undoStack, &redoStack);  // Undo first action (type 'Hello')

    // Clean up the allocated memory
    while (undoStack) {
        free(pop(&undoStack));
    }
    while (redoStack) {
        free(pop(&redoStack));
    }

    return 0;
}
