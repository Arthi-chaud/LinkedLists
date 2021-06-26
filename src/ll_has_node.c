/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_has_node
*/

#include "linked_list.h"

bool ll_has_node(llist_t *list, node_t *node)
{
    node_t *cursor = NULL;

    if (!node || !ll_is_correct(list) || ll_is_empty(list))
        return false;
    if (list->first == node)
        return true;
    cursor = list->first->next;
    while (cursor != list->first && cursor) {
        if (cursor == node)
            return true;
        cursor = cursor->next;
    }
    return false;
}