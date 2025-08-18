#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedlist.h"

// Create a new queue
LinkedList* linkedlist_init() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

//get size of linked list
int linkedlist_getSize(LinkedList *list) {
    if (list == NULL) {
        fprintf(stderr, "LinkedList is NULL\n");
        return -1; // Error code for NULL list
    }
    return list->size;
}
Node* getNodeAtIndex(LinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) {
        return NULL;
    }
    
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}
//Remove element at index
int linkedlist_removeAtIndex(LinkedList *list, int index) {
    if (list == NULL || index < 0 || index >= list->size) {
        fprintf(stderr, "Invalid linked list or index\n");
        return -1; // Error code for invalid list or index
    }
    Node *nodeToRemove;
    int removedValue;

    if (index == 0) {
        // Remove head
        nodeToRemove = list->head;
        removedValue = nodeToRemove->data;
        list->head = nodeToRemove->next;
    } else {
        Node* prevNode = getNodeAtIndex(list, index - 1);
        nodeToRemove = prevNode->next;
        removedValue = nodeToRemove->data;
        prevNode->next = nodeToRemove->next;              
    }
    free(nodeToRemove);
    list->size--;
    return removedValue; // Return the removed value
}
//add element at index
int linkedlist_addAtIndex(LinkedList *list, int index, int value) {
    if (list == NULL || index < 0 || index > list->size) {
        fprintf(stderr, "Invalid linked list or index\n");
        return -1; // Error code for invalid list or index
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1; // Error code for memory allocation failure
    }
    newNode->data = value;
    newNode->next = NULL;
    if (index == 0) {
        // Insert at head
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* prevNode = getNodeAtIndex(list, index - 1);
        if (prevNode == NULL) {
            free(newNode);
            fprintf(stderr, "Invalid index for insertion\n");
            return -1; // Error code for invalid index
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
    list->size++;
    return 0; // Success
}   
//Search for a value and return its index
int linkedlist_searchValueAndReturnAtIndex(LinkedList *list, int value) {
    if (list == NULL) {
        fprintf(stderr, "LinkedList is NULL\n");
        return -1; // Error code for NULL list
    }
    Node *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == value) {
            return index; // Return the index of the found value
        }
        current = current->next;
        index++;
    }
    return -1; // Value not found
}
// Clear all elements in the linked list
void linkedlist_clearAll(LinkedList *list) {
    if (list == NULL) {
        fprintf(stderr, "LinkedList is NULL\n");
        return; // Nothing to clear
    }
    Node *current = list->head;
    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->size = 0;
    free(list); // Free the linked list structure itself
}
// print linked list elements
void printLinkedList(LinkedList *list) {
    if (list == NULL) {
        fprintf(stderr, "LinkedList is NULL\n");
        return; // Nothing to print
    }
    Node *current = list->head;
    printf("LinkedList elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}