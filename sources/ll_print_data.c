/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_print_data
*/

#include "linked_list.h"

bool ll_print_data(llist_t *list, int (*print_function)(void *data))
{
    node_t *node = NULL;

    if (!ll_is_correct(list))
        return false;
    if (ll_is_empty(list))
        return true;
    node = list->first;
    (*print_function)(node->data);
    for (node = node->next; node != list->first; node = node->next)
        (*print_function)(node->data);
    return true;
}