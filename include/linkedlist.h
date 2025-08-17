#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;              // Data stored in the node
    struct Node *next;    // Pointer to the next node in the list
} Node;

typedef struct LinkedList {
    Node *head;           // Pointer to the first node in the list
    int size;             // Current number of elements in the linked list
} LinkedList;

// Function declarations
LinkedList* init(); // Create a new linked list
int getSize(LinkedList *list); // Get the current size of the linked list
int removeAtIndex(LinkedList *list, int index); // Remove an element at a specific index
int addAtIndex(LinkedList *list, int index, int value); // Add an element at a specific index
int searchValueAndReturnAtIndex(LinkedList *list, int value); // Search for a value and return its index
void clearAll(LinkedList *list); // Clear all elements in the linked list

// Support functions
void printLinkedList(LinkedList *list); // Print the current elements in the linked list

#endif // LINKEDLIST_H