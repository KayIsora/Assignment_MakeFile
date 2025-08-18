#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/linkedlist.h"

void testStack() {
    printf("\n=== Test Stack ===\n");
    Stack* stack = stack_init();

    int choice, value, index, result;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Add element (addAtIndex)\n");
        printf("2. Remove element (removeAtIndex)\n");
        printf("3. Search (SearchValueAndReturnAtIndex)\n");
        printf("4. Size (getsize)\n");
        printf("5. Print stack\n");
        printf("6. Clear all\n");
        printf("7. Back to main menu\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter value: ");
                scanf("%d", &value);
                result = stack_addAtIndex(stack, index, value);
                break;

            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                result = stack_removeAtIndex(stack, index);
                if (result != -1) {
                    printf("Removed value: %d\n", result);
                } else {
                    printf("Remove failed\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = stack_SearchValueAndReturnAtIndex(stack, value);
                if (result != -1) {
                    printf("Found at index: %d\n", result);
                } else {
                    printf("Not found\n");
                }
                break;

            case 4:
                printf("Stack size: %d\n", stack_getsize(stack));
                break;

            case 5:
                printStack(stack);
                break;

            case 6:
                stack_ClearAll(stack);
                printf("All cleared\n");
                break;

            case 7:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

void testQueue() {
    printf("\n=== Test Queue ===\n");
    Queue* queue = queue_init();

    int choice, value, index, result;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Add element (addAtIndex)\n");
        printf("2. Remove element (removeAtIndex)\n");
        printf("3. Search (SearchValueAndReturnAtIndex)\n");
        printf("4. Size (getsize)\n");
        printf("5. Print queue\n");
        printf("6. Clear all\n");
        printf("7. Back to main menu\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter value: ");
                scanf("%d", &value);
                result = queue_addAtIndex(queue, index, value);
                break;

            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                result = queue_removeAtIndex(queue, index);
                if (result != -1) {
                    printf("Removed value: %d\n", result);
                } else {
                    printf("Remove failed\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = queue_searchValueAndReturnAtIndex(queue, value);
                if (result != -1) {
                    printf("Found at index: %d\n", result);
                } else {
                    printf("Not found\n");
                }
                break;

            case 4:
                printf("Queue size: %d\n", queue_getSize(queue));
                break;

            case 5:
                printQueue(queue);
                break;

            case 6:
                queue_clearAll(queue);
                printf("All cleared\n");
                break;

            case 7:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

void testLinkedList() {
    printf("\n=== Test Linked List ===\n");
    LinkedList* list = linkedlist_init();

    int choice, value, index, result;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Add element (addAtIndex)\n");
        printf("2. Remove element (removeAtIndex)\n");
        printf("3. Search (SearchValueAndReturnAtIndex)\n");
        printf("4. Size (getsize)\n");
        printf("5. Print list\n");
        printf("6. Clear all\n");
        printf("7. Back to main menu\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Enter value: ");
                scanf("%d", &value);
                result = linkedlist_addAtIndex(list, index, value);
                break;

            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                result = linkedlist_removeAtIndex(list, index);
                if (result != -1) {
                    printf("Removed value: %d\n", result);
                } else {
                    printf("Remove failed\n");
                }
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = linkedlist_searchValueAndReturnAtIndex(list, value);
                if (result != -1) {
                    printf("Found at index: %d\n", result);
                } else {
                    printf("Not found\n");
                }
                break;

            case 4:
                printf("List size: %d\n", linkedlist_getSize(list));
                break;

            case 5:
                printLinkedList(list);
                break;

            case 6:
                linkedlist_clearAll(list);
                printf("All cleared\n");
                break;

            case 7:
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPlease select the data structure you want to work on:\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Linked List\n");
        printf("4. Exit\n");
        printf("Your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                testStack();
                break;
            case 2:
                testQueue();
                break;
            case 3:
                testLinkedList();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
