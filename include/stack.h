#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int *data;      // Pointer to the stack's data
    int top;    // Current number of elements in the stack
    int capacity; // Maximum number of elements the stack can hold
} Stack;

//Function declarations
Stack* inti(); //Create a new stack
int getsize(Stack *stack);//Get the current size of the stack
int removeAtIndex(Stack *stack, int index); //Remove an element at a specific index
int addAtIndex(Stack *stack, int index, int value); //Add an element at a specific index
int SearchValueAndReturnAtIndex(Stack *stack, int value); //Search for a value and return its index
void ClearAll(Stack *stack); //Clear all elements in the stack

//Support functions
void printStack(Stack *stack); //Print the current elements in the stack

#endif // STACK_H