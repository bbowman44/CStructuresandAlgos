#include "../lib/ilist.h"

int main()
{
    //declare a struct with a node member and other members with values

    typedef struct container {
        int32_t value;
        ilist_node_t node;
    } container;

    //declare a few container struct with value and node, then the list, then push them onto the list
    ilist_t list = {0};

    //declare the nodes

    container cont1 = {0};
    container cont2 = {0};
    container cont3 = {0};
    container cont4 = {0};

    cont1.value = 356;
    cont2.value = 23;
    cont3.value = 42;
    cont4.value = 1155;

    ilist_push_front(&list, &cont1.node);
    ilist_push_front(&list, &cont2.node);
    ilist_push_front(&list, &cont3.node);
    ilist_push_front(&list, &cont4.node);
    //order of 4->3->2->1 in the list

    //navigate the node and print the values of the nodes from the parent stuct
    ilist_node_t *curr = list.head;
    int32_t count = 0;
    while(curr != NULL)
    {
        count++;
        container *my_container = container_of(curr, container, node);
        printf("The current value of pointer #%d is: %d\n", count, my_container->value);
        curr = curr->next;
    }

    bool removed = ilist_remove(&list, &cont2.node);

    if(removed)
    {
       printf("Node removed successfully\n");
    }

    curr = list.head;
    count = 0;
    while(curr != NULL)
    {
        count++;
        container *my_container = container_of(curr, container, node);
        printf("The current value of pointer #%d is: %d\n", count, my_container->value);
        curr = curr->next;
    }
    return 0;
}