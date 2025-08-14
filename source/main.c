#include <stdio.h>
#include "../include/linkedlist.h"
#include "../include/stack.h"
#include "../include/queue.h"

int main()
{
    printf("Please select data structure you like to work on:\n1.Stack\n2.Queue\n3.Linked List\n4.Exit\n-->");
    int choice = 0;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            stack_operations();
            break;
        case 2:
            queue_operations();
            break;
        case 3:
            linkedlist_operations();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    return 0;
}
