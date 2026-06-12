#include "../lib/list.h"
#include <stdio.h>

void printList(const list_t *list)
{
    printf("Current list:");
    for(node_t *travNode = list->head; travNode != NULL; travNode = travNode->next)
    {
        printf(" %d", travNode->value);
    }
    printf("\n");
}

//The main function here is a bit exagerated and has A LOT of uneccessary checks. I am sure there is a better way to check for null and the boolean being returned.
//I could porbably consolidate the null checks into the function returns instead of having to check each time and duplicating code.
//with the booleans I could call them directly in the if statement and probably implement a turnary operator to lower the lines of code and make it more readable.
//However this is just a demonstration and good practices like this are more important for actual implementation of my code base projects and not my test projects.
int main(void)
{
    list_t list = {0};
    node_t node1;
    node_t node2;
    node_t node3;
    node_t node4;
    node_t node5;
    node1.value = 23;
    node2.value = 44;
    node3.value = 12;
    node4.value = 9;
    node5.value = 4385;

    list_push_front(&list, &node1);
    list_push_front(&list, &node2);
    list_push_front(&list, &node3);
    list_push_front(&list, &node4);
    list_push_front(&list, &node5);

    printf("After pushing five nodes:\n");
    printList(&list);

    node_t *foundNode = list_find(&list, 12);
    if(foundNode != NULL)
    {
        printf("Found a node with value: %d\n", foundNode->value);
    }
    else
    {
        printf("Value 12 was not found\n");
    }

    foundNode = list_find(&list, 999);
    if(foundNode != NULL)
    {
        printf("Found a node with value: %d\n", foundNode->value);
    }
    else
    {
        printf("Value 999 was not found\n");
    }

    bool REMOVED = list_remove(&list, 4385);
    if(REMOVED)
    {
        printf("Removed the head value 4385\n");
    }
    else
    {
        printf("Value 4385 was not removed\n");
    }
    printList(&list);

    REMOVED = list_remove(&list, 12);
    if(REMOVED)
    {
        printf("Removed the middle value 12\n");
    }
    else
    {
        printf("Value 12 was not removed\n");
    }
    printList(&list);

    REMOVED = list_remove(&list, 23);
    if(REMOVED)
    {
        printf("Removed the tail value 23\n");
    }
    else
    {
        printf("Value 23 was not removed\n");
    }
    printList(&list);

    REMOVED = list_remove(&list, 999);
    if(REMOVED)
    {
        printf("Removed value 999\n");
    }
    else
    {
        printf("Value 999 was not in the list\n");
    }
    printList(&list);

    foundNode = list_find(&list, 23);
    if(foundNode != NULL)
    {
        printf("Found a node with value: %d\n", foundNode->value);
    }
    else
    {
        printf("Value 23 is gone after being removed\n");
    }

    list_remove(&list, 44);
    list_remove(&list, 9);
    printf("After draining the remaining nodes:\n");
    printList(&list);

    foundNode = list_find(&list, 9);
    if(foundNode != NULL)
    {
        printf("Found a node with value: %d\n", foundNode->value);
    }
    else
    {
        printf("The list is empty, value 9 not found\n");
    }

    return 0;
}