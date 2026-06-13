#ifndef ILIST_H
#define ILIST_H

#include <stddef.h>
#include <stdbool.h>

typedef struct ilist_node
{
    struct ilist_node *next;
} ilist_node_t;

typedef struct
{
    ilist_node_t *head;
} ilist_t;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void ilist_push_front(ilist_t *list, ilist_node_t *node);
bool ilist_remove(ilist_t *list, ilist_node_t *node);

#endif