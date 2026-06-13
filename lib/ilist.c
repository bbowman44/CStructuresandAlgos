#include "ilist.h"

void ilist_push_front(ilist_t *list, ilist_node_t *node)
{
    node->next = list->head;
    list->head = node;
}

bool ilist_remove(ilist_t *list, ilist_node_t *node)
{
    if(list->head == NULL)
    {
        return false;
    }
    
    if(list->head == node)
    {
        list->head = list->head->next;
        return true;
    }

    ilist_node_t *prev = list->head;
    ilist_node_t *curr = list->head->next;

    while(curr != NULL)
    {
        if(curr == node)
        {
            prev->next = curr->next;
            return true;
        }

        prev = prev->next;
        curr = curr->next;
    }
    return false;
}