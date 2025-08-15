#ifndef STACK_H
#define STACK_H
#include <stddef.h>
#include "person.h"

typedef struct {
    Person *data;
    size_t capacity;
    size_t size; // top == size
} Stack;

void   Stack_init(Stack *s, size_t capacity);
size_t Stack_getsize(const Stack *s);
int    Stack_addAtIndex(Stack *s, size_t index, Person value);        // 0..size
int    Stack_removeAtIndex(Stack *s, size_t index, Person *outValue); // 0..size-1
int    Stack_SearchValueAndReturnAtIndex(const Stack *s, int id);     // by id
void   Stack_ClearAll(Stack *s);

#endif
