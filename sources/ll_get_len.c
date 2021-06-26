/*
** EPITECH PROJECT, 2020
** ll_len.c
** File description:
** ll_len
*/

#include "linked_list.h"

size_t ll_get_len(llist_t *list)
{
    int len = 1;
    node_t *cursor = NULL;
    node_t *first = NULL;

    if (!ll_is_correct(list))
        return (size_t)LL_ERROR;
    if (!list->first)
        return 0;
    first = list->first;
    cursor = first->next;
    while (cursor != first) {
        len++;
        cursor = cursor->next;
    }
    return len;
}