#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stddef.h>
#include "person.h"

typedef struct Node {
    Person value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    size_t size;
} List;

void   List_init(List *l);
size_t List_getsize(const List *l);
int    List_addAtIndex(List *l, size_t index, Person value);       // 0..size
int    List_removeAtIndex(List *l, size_t index, Person *outValue);// 0..size-1
int    List_SearchValueAndReturnAtIndex(const List *l, int id);    // by id
void   List_ClearAll(List *l);

#endif
