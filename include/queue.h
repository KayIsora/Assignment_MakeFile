#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>
#include "person.h"

typedef struct {
    Person *data;
    size_t capacity;
    size_t size;
} Queue;

void   Queue_init(Queue *q, size_t capacity);
size_t Queue_getsize(const Queue *q);
int    Queue_addAtIndex(Queue *q, size_t index, Person value);        // 0..size
int    Queue_removeAtIndex(Queue *q, size_t index, Person *outValue); // 0..size-1
int    Queue_SearchValueAndReturnAtIndex(const Queue *q, int id);
void   Queue_ClearAll(Queue *q);

#endif
