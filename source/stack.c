#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/stack.h"

#define INITIAL_CAPACITY 5

static int ensure_capacity(Stack *stack, int min_cap) {
    if (stack->capacity >= min_cap) return 0;
    int new_cap = stack->capacity ? stack->capacity * 2 : INITIAL_CAPACITY;
    if (new_cap < min_cap) new_cap = min_cap;
    int *newData = (int *)realloc(stack->data, new_cap * sizeof(int));
    if (!newData) {
        fprintf(stderr, "Memory reallocation failed\n");
        return -1;
    }
    stack->data = newData;
    stack->capacity = new_cap;
    return 0;
}

// Create new stack
Stack* stack_init(void) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    stack->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    if (!stack->data) {
        fprintf(stderr, "Memory allocation for stack data failed\n");
        free(stack);
        return NULL;
    }
    stack->size = 0;
    stack->capacity = INITIAL_CAPACITY;
    return stack;
}

// Get size of stack
int stack_getsize(Stack *stack) {
    if (!stack) {
        fprintf(stderr, "Stack is NULL\n");
        return -1;
    }
    return stack->size;
}

// Add only at TOP (index must equal size)  => PUSH
int stack_addAtIndex(Stack *stack, int index, int value) {
    if (!stack) {
        fprintf(stderr, "Stack is NULL\n");
        return -1;
    }
    if (index != stack->size) {
        fprintf(stderr, "Stack addAtIndex allowed only at top (index == size). Got %d, size=%d\n",
                index, stack->size);
        return -1;
    }
    if (ensure_capacity(stack, stack->size + 1) != 0) return -1;
    stack->data[stack->size++] = value;   // push
    return 0;
}

// Remove only at TOP (index must equal size-1)  => POP
int stack_removeAtIndex(Stack *stack, int index) {
    if (!stack) {
        fprintf(stderr, "Stack is NULL\n");
        return -1;
    }
    if (stack->size == 0) {
        fprintf(stderr, "Pop from empty stack\n");
        return -1;
    }
    if (index != stack->size - 1) {
        fprintf(stderr, "Stack removeAtIndex allowed only at top (index == size-1). Got %d, size=%d\n",
                index, stack->size);
        return -1;
    }
    int removedValue = stack->data[stack->size - 1];
    stack->size--;                         // pop
    return removedValue;                   // trả về giá trị đã pop (đúng với kiểu bạn đang dùng)
}

// Search value (linear scan) — OK cho stack
int stack_SearchValueAndReturnAtIndex(Stack *stack, int value) {
    if (!stack) {
        fprintf(stderr, "Stack is NULL\n");
        return -1;
    }
    for (int i = 0; i < stack->size; i++) {
        if (stack->data[i] == value) return i;
    }
    return -1;
}

// Clear all
void stack_ClearAll(Stack *stack) {
    if (!stack) return;
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
    free(stack);
}

// (tuỳ chọn) tiện ích đúng nghĩa push/pop nếu bạn muốn gọi cho gọn
int stack_push(Stack *stack, int value) {
    return stack_addAtIndex(stack, stack_getsize(stack), value);
}
int stack_pop(Stack *stack, int *out) {
    if (!stack || stack->size == 0) return -1;
    int idx = stack->size - 1;
    int val = stack_removeAtIndex(stack, idx);
    if (val < 0) return -1;
    if (out) *out = val;
    return 0;
}

// Debug print
void printStack(Stack *stack) {
    if (!stack) { fprintf(stderr, "Stack is NULL\n"); return; }
    printf("Stack(top -> bottom): ");
    for (int i = stack->size - 1; i >= 0; --i) printf("%d ", stack->data[i]);
    printf("\n");
}
