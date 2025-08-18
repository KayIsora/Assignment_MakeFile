#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int *data;      // Pointer to the stack's data
    int size;    // Current number of elements in the stack
    int capacity; // Maximum number of elements the stack can hold
} Stack;

//Function declarations
Stack* stack_init(); //Create a new stack
int stack_getsize(Stack *stack); //Get the current size of the stack
int stack_removeAtIndex(Stack *stack, int index); //Remove an element at a specific
int stack_addAtIndex(Stack *stack, int index, int value); //Add an element at a specific index
int stack_SearchValueAndReturnAtIndex(Stack *stack, int value); //Search for a
void stack_ClearAll(Stack *stack); //Clear all elements in the stack
//Support functions
void printStack(Stack *stack); //Print the current elements in the stack

#endif // STACK_H