#include <stdio.h>
#include <string.h>
#include "../include/person.h"
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/linkedlist.h"

static Person P(int id, const char* name, int age){
    Person x; x.id=id; x.age=age;
    strncpy(x.name, name, NAME_MAX_LEN);
    x.name[NAME_MAX_LEN] = '\0';
    return x;
}

static void demo_stack(void){
    Stack s; Stack_init(&s, 8);
    Stack_addAtIndex(&s, Stack_getsize(&s), P(1,"Alice",20)); // push
    Stack_addAtIndex(&s, Stack_getsize(&s), P(2,"Bob",21));
    printf("Stack size = %zu, find id=2 -> index %d\n",
           Stack_getsize(&s), Stack_SearchValueAndReturnAtIndex(&s,2));
    Person out; Stack_removeAtIndex(&s, Stack_getsize(&s)-1, &out); // pop
    printf("Popped: %s\n", out.name);
    Stack_ClearAll(&s);
}

static void demo_queue(void){
    Queue q; Queue_init(&q, 8);
    Queue_addAtIndex(&q, q.size, P(3,"Carol",22));           // enqueue
    Queue_addAtIndex(&q, q.size, P(4,"Dave",23));
    printf("Queue size = %zu, find id=3 -> index %d\n",
           Queue_getsize(&q), Queue_SearchValueAndReturnAtIndex(&q,3));
    Person out; Queue_removeAtIndex(&q, 0, &out);            // dequeue
    printf("Dequeued: %s\n", out.name);
    Queue_ClearAll(&q);
}

static void demo_list(void){
    List l; List_init(&l);
    List_addAtIndex(&l, 0, P(5,"Eve",24));   // head
    List_addAtIndex(&l, 1, P(6,"Frank",25)); // tail
    printf("List size = %zu, find id=6 -> index %d\n",
           List_getsize(&l), List_SearchValueAndReturnAtIndex(&l,6));
    Person out; List_removeAtIndex(&l, 0, &out);
    printf("Removed head: %s\n", out.name);
    List_ClearAll(&l);
}

int main(void){
    int choice;
    do{
        printf("Please select data structure you like to work on:\n");
        printf("1. Stack\n2. Queue\n3. Linked List\n4. Exit\n> ");
        if(scanf("%d",&choice)!=1) return 0;
        if(choice==1) demo_stack();
        else if(choice==2) demo_queue();
        else if(choice==3) demo_list();
    }while(choice!=4);
    return 0;
}
