#include "list.h"

void list_push_front(list_t *list, node_t *n)
{
    n->next = list->head;
    list->head = n;
}

node_t *list_find(const list_t *list, int32_t value)
{
    node_t *currentNode = list->head;
    while(currentNode != NULL)
    {
        if(currentNode->value == value)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
 
    return NULL;
}

bool list_remove(list_t *list, int32_t value)
{
    if(list->head == NULL)
    {
        return false;
    }
    if(list->head->value == value)
    {
        list->head = list->head->next;
        return true;
    }

    node_t *prevNode = list->head;
    node_t *currNode = prevNode->next;

    while(currNode != NULL)
    {
        if(currNode->value == value)
        {
            prevNode->next = currNode->next;
            return true;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    return false;
}