/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_revert
*/

#include "linked_list.h"

bool ll_revert(llist_t *list)
{
    node_t *first = NULL;
    node_t *cursor = NULL;
    node_t *next = NULL;

    if (!ll_is_correct(list))
        return false;
    if (ll_is_empty(list))
        return true;
    first = list->first;
    cursor = first->next;
    for (; cursor != first; cursor = next) {
        next = cursor->next;
        cursor->next = cursor->prev;
        cursor->prev = next;
    }
    next = cursor->next;
    cursor->next = cursor->prev;
    cursor->prev = next;
    list->first = cursor->next;
    return true;
}