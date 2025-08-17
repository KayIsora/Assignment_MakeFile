#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/stack.h"
#define INITIAL_CAPACITY 10

//Creat new stack
Stack* inti() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    stack-> data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation for stack data failed\n");
        free(stack);
        return NULL;
    }
    stack->size = 0;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}
//get size of stack
int getsize(Stack *stack) {
    if (stack == NULL) {
        fprintf(stderr, "Stack is NULL\n");
        return -1; // Error code for NULL stack
    }
    return stack->size;
}
