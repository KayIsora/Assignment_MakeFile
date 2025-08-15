#include <stdlib.h>
#include <string.h>
#include "../include/queue.h"

void Queue_init(Queue *q, size_t capacity){
    q->data = (Person*)malloc(sizeof(Person)*capacity);
    q->capacity = capacity;
    q->size = 0;
}
size_t Queue_getsize(const Queue *q){ return q->size; }

int Queue_addAtIndex(Queue *q, size_t index, Person value){
    if(index > q->size || q->size == q->capacity) return -1;
    memmove(&q->data[index+1], &q->data[index], (q->size-index)*sizeof(Person));
    q->data[index] = value;
    q->size++;
    return 0;
}
int Queue_removeAtIndex(Queue *q, size_t index, Person *outValue){
    if(index >= q->size) return -1;
    if(outValue) *outValue = q->data[index];
    memmove(&q->data[index], &q->data[index+1], (q->size-index-1)*sizeof(Person));
    q->size--;
    return 0;
}
int Queue_SearchValueAndReturnAtIndex(const Queue *q, int id){
    for(size_t i=0;i<q->size;i++) if(q->data[i].id==id) return (int)i;
    return -1;
}
void Queue_ClearAll(Queue *q){
    free(q->data);
    q->data=NULL; q->capacity=0; q->size=0;
}
