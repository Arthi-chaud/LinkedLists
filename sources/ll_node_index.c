/*
** EPITECH PROJECT, 2020
** ll_node_index.c
** File description:
** ll_node_index
*/

#include "linked_list.h"

node_t *ll_get_node_by_index(llist_t *list, int index)
{
    node_t *cursor = NULL;

    if (!ll_is_correct(list))
        return NULL;
    cursor = list->first;
    while (index) {
        if (index > 0)
            cursor = cursor->next;
        else
            cursor = cursor->prev;
        if (cursor == list->first)
            return cursor->prev;
        index -= (index / (index < 0 ? (-1 * index) : index));
    }
    return cursor;
}

void *ll_get_data_by_index(llist_t *list, int index)
{
    node_t *node = ll_get_node_by_index(list, index);

    if (node)
        return node->data;
    return NULL;
}

size_t ll_get_node_index(llist_t *list, node_t *node)
{
    node_t *cursor = NULL;
    int index = 0;

    if (!ll_is_correct(list) || !node)
        return (size_t)LL_ERROR;
    if (!ll_has_node(list, node))
        return (size_t)LL_ERROR;
    cursor = list->first;
    for (; cursor != node; index++)
        cursor = cursor->next;
    return index;
}