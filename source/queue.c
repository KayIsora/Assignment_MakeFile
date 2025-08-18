#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/queue.h"

#define INITIAL_CAPACITY 5

//Init queue
Queue* queue_init() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    queue->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (queue->data == NULL) {
        fprintf(stderr, "Memory allocation for queue data failed\n");
        free(queue);
        return NULL;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = INITIAL_CAPACITY;
    return queue;
}

//Get size of queue
int queue_getSize(Queue *queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return -1; // Error code for NULL queue
    }
    return queue->size;
}
//Remove element at index
// Add elements to the end of the queue (enqueue)
int queue_addAtIndex(Queue *queue, int index, int value) { 
if (queue == NULL) { 
fprintf(stderr, "Queue is NULL\n"); 
return -1; 
} 
if (index != queue->size) { // Only allowed to add at the end, i.e. index == size 
fprintf(stderr, "Invalid queue add index. Only allowed at rear (index == size).\n"); 
return -1; 
} 

// Resize if needed 
if (queue->size >= queue->capacity) { 
int newCapacity = queue->capacity * 2; 
int *newData = (int *)malloc(newCapacity * sizeof(int)); 
if (newData == NULL) { 
fprintf(stderr, "Memory reallocation failed\n"); 
return -1; 
} 
// Copy data according to current queue order 
for (int i = 0; i < queue->size; i++) { 
newData[i] = queue->data[(queue->front + i) % queue->capacity]; 
} 
free(queue->data); 
queue->data = newData; 
queue->front = 0; 
queue->rear = queue->size - 1; 
queue->capacity = newCapacity; 
} 

// Update rear and add new element 
queue->rear = (queue->rear + 1) % queue->capacity; 
queue->data[queue->rear] = value; 
queue->size++; 

return 0; // Success
}

// Delete elements at the beginning of the queue (dequeue)
int queue_removeAtIndex(Queue *queue, int index) { 
if (queue == NULL) { 
fprintf(stderr, "Queue is NULL\n"); 
return -1; 
} 
if (queue->size == 0) { 
fprintf(stderr, "Queue is empty\n"); 
return -1; 
} 
if (index != 0) { // Only allow deletion at the beginning, i.e. index == 0 
fprintf(stderr, "Invalid queue remove index. Only allowed at front (index == 0).\n"); 
return -1; 
} 

int removedValue = queue->data[queue->front]; 
queue->front = (queue->front + 1) % queue->capacity; 
queue->size--;

return removedValue; // Returns the removed element
}

//Search for a value and return its index
int queue_searchValueAndReturnAtIndex(const Queue *queue, int value) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return -1; // Error code for NULL queue
    }
    for (int i = 0; i < queue->size; i++) {
        int pos = (queue->front + i) % queue->capacity;
        if (queue->data[pos] == value) {
            return i; // Return the index relative to the queue
        }
    }
    return -1; // Value not found
}
//Clear all elements in the queue
void queue_clearAll(Queue *queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return; // Nothing to clear
    }
    free(queue->data);
    queue->data = NULL;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = INITIAL_CAPACITY;
    free(queue);
}
// Print the current elements in the queue
void printQueue(Queue *queue) {
    if (queue == NULL) {
        fprintf(stderr, "Queue is NULL\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        int pos = (queue->front + i) % queue->capacity;
        printf("%d ", queue->data[pos]);
    }
    printf("\n");
}

