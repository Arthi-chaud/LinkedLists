/*
** EPITECH PROJECT, 2020
** ll_free_list.c
** File description:
** ll_free_list
*/

#include "linked_list.h"
#include <stdlib.h>

static bool ll_destroy_list(llist_t *list, int destroy_data)
{
    node_t *next = NULL;
    node_t *cursor = NULL;
    int free_node_return = 0;

    if (!ll_is_correct(list))
        return false;
    if (ll_is_empty(list))
        return true;
    for (cursor = list->first->next; cursor
    && cursor != list->first; cursor = next) {
        next = cursor->next;
        free_node_return =
        destroy_data ? ll_free_node_and_data(&cursor) : ll_free_node(&cursor);
        if (!free_node_return)
            return false;
        cursor = next;
    }
    if (destroy_data)
        return ll_free_node_and_data(&list->first);
    return ll_free_node(&list->first);
}

bool ll_free_list(llist_t *list)
{
    bool return_value = ll_destroy_list(list, 0);

    if (return_value)
        free(list);
    return return_value;
}

bool ll_free_list_and_data(llist_t *list)
{
    bool return_value = ll_destroy_list(list, 1);

    if (return_value)
        free(list);
    return return_value;
}