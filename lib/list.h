#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct node {
    int32_t      value;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
} list_t;

void list_push_front(list_t *list, node_t *n);

node_t *list_find(const list_t *list, int32_t value);

bool list_remove(list_t *list, int32_t value);

#endif