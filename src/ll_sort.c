/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_sort
*/

#include "linked_list.h"

static bool ll_swap(llist_t *list, node_t *node1,
int (*cmp)(void *data1, void *data2))
{
    node_t *node2 = node1->next;
    int node2_index = ll_get_node_index(list, node2);
    int swap = (*cmp)(node1->data, node2->data);

    if (swap > 0) {
        ll_move_node(list, node1, node2_index);
        if (list->first == node1)
            list->first = node2;
        return true;
    }
    return false;
}

static bool ll_sort(llist_t *list, int (*cmp)(void *data1, void *data2))
{
    int is_sorted = 0;
    node_t *first = NULL;

    if (!ll_is_correct(list))
        return false;
    if (ll_get_len(list) <= 1)
        return true;
    if (ll_get_len(list) == 2) {
        ll_swap(list, list->first, cmp);
        return true;
    }
    for (first = list->first; !is_sorted; first = list->first) {
        is_sorted = ll_swap(list, first, cmp) ? 0 : 1;
        first = list->first;
        for (node_t *tmp = first->next; tmp->next != first; tmp = tmp->next)
            is_sorted = ll_swap(list, tmp, cmp) ? 0 : is_sorted;
    }
    return true;
}

bool ll_sort_asc(llist_t *list, int (*cmp)(void *data1, void *data2))
{
    return ll_sort(list, cmp);
}

#include <stdio.h>

bool ll_sort_desc(llist_t *list, int (*cmp)(void *data1, void *data2))
{
    if (!ll_sort(list, cmp))
        return false;
    return ll_revert(list);
}