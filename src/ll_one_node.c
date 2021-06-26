/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_one_node
*/

#include "linked_list.h"

llist_t *ll_one_node(void *data)
{
    node_t *node = ll_create_node(data);
    llist_t *list = ll_create_list();

    if (!list || !node)
        return NULL;
    list->first = node;
    node->next = node;
    node->prev = node;
    return list;
}