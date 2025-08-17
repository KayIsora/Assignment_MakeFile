#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *data;      // Pointer to the queue's data
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int size;       // Current number of elements in the queue
    int capacity;  // Maximum number of elements the queue can hold
} Queue;

// Function declarations
Queue* init(); // Create a new queue
int getSize(Queue *queue); // Get the current size of the queue
int removeAtIndex(Queue *queue, int index); // Remove an element at a specific index
int addAtIndex(Queue *queue, int index, int value); // Add an element at a specific index
int searchValueAndReturnAtIndex(Queue *queue, int value); // Search for a value and return its index
void clearAll(Queue *queue); // Clear all elements in the queue 

// Support functions
void printQueue(Queue *queue); // Print the current elements in the queue

#endif // QUEUE_H