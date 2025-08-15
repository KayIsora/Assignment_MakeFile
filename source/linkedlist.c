#include <stdlib.h>
#include "../include/linkedlist.h"

void List_init(List *l){ l->head=NULL; l->size=0; }
size_t List_getsize(const List *l){ return l->size; }

int List_addAtIndex(List *l, size_t index, Person value){
    if(index > l->size) return -1;
    Node *n = (Node*)malloc(sizeof(Node));
    if(!n) return -1;
    n->value = value;
    if(index==0){
        n->next = l->head; l->head = n;
    }else{
        Node *p = l->head;
        for(size_t i=0;i<index-1;i++) p = p->next;
        n->next = p->next; p->next = n;
    }
    l->size++; return 0;
}

int List_removeAtIndex(List *l, size_t index, Person *outValue){
    if(index >= l->size) return -1;
    Node *del;
    if(index==0){
        del = l->head; l->head = del->next;
    }else{
        Node *p = l->head;
        for(size_t i=0;i<index-1;i++) p = p->next;
        del = p->next; p->next = del->next;
    }
    if(outValue) *outValue = del->value;
    free(del); l->size--; return 0;
}

int List_SearchValueAndReturnAtIndex(const List *l, int id){
    Node *p = l->head; size_t idx=0;
    while(p){ if(p->value.id==id) return (int)idx; p=p->next; idx++; }
    return -1;
}

void List_ClearAll(List *l){
    Node *p=l->head;
    while(p){ Node *n=p->next; free(p); p=n; }
    l->head=NULL; l->size=0;
}
