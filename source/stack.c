#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"

void Stack_init(Stack *s, size_t capacity){
    s->data = (Person*)malloc(sizeof(Person)*capacity);
    s->capacity = capacity;
    s->size = 0;
}
size_t Stack_getsize(const Stack *s){ return s->size; }

int Stack_addAtIndex(Stack *s, size_t index, Person value){
    if(index > s->size || s->size == s->capacity) return -1;
    memmove(&s->data[index+1], &s->data[index], (s->size-index)*sizeof(Person));
    s->data[index] = value;
    s->size++;
    return 0;
}
int Stack_removeAtIndex(Stack *s, size_t index, Person *outValue){
    if(index >= s->size) return -1;
    if(outValue) *outValue = s->data[index];
    memmove(&s->data[index], &s->data[index+1], (s->size-index-1)*sizeof(Person));
    s->size--;
    return 0;
}
int Stack_SearchValueAndReturnAtIndex(const Stack *s, int id){
    for(size_t i=0;i<s->size;i++) if(s->data[i].id==id) return (int)i;
    return -1;
}
void Stack_ClearAll(Stack *s){
    free(s->data);
    s->data=NULL; s->capacity=0; s->size=0;
}
