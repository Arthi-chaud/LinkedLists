/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_remove_node
*/

#include "linked_list.h"

bool ll_remove_node(llist_t *list, node_t *node)
{
    int list_prev_len = 0;

    if (!ll_is_correct(list) || ll_is_empty(list)
        || !ll_has_node(list, node))
        return false;
    list_prev_len = ll_get_len(list);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (list->first == node)
        list->first = node->next;
    node->prev = NULL;
    node->next = NULL;
    if (list_prev_len == 1)
        list->first = NULL;
    return true;
}

bool ll_remove_node_at_index(llist_t *list, int index)
{
    node_t *node = ll_get_node_by_index(list, index);

    if (node)
        return ll_remove_node(list, node);
    return false;
}

bool ll_remove_node_by_data(llist_t *list, void *data,
bool (*cmp)(void *, void *))
{
    node_t *node = NULL;
    size_t list_size = ll_get_len(list);

    for (size_t i = 0; i < list_size; i++) {
        node = ll_get_node_by_index(list, i);
        if (cmp(data, node->data)) {
            ll_remove_node(list, node);
            return true;
        }
    }
    return false;
}