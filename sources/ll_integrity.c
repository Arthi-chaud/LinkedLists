/*
** EPITECH PROJECT, 2020
** ll_integrity.c
** File description:
** ll_integrity
*/

#include "linked_list.h"

bool ll_is_correct(llist_t *list)
{
    node_t *first = NULL;
    node_t *cursor = NULL;

    if (!list)
        return false;
    first = list->first;
    cursor = first;
    if (!first)
        return true;
    if (!first->next || !first->prev)
        return false;
    cursor = cursor->next;
    for (;cursor != first; cursor = cursor->next) {
        if (!cursor)
            return false;
        if (!cursor->next || !cursor->prev)
            return false;
    }
    return true;
}