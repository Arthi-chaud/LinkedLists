/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_insert_node
*/

#include "linked_list.h"

static void ll_add_node(llist_t *list, node_t *new_node, int index)
{
    node_t *node_to_move = ll_get_node_by_index(list, index);

    if (index >= 0 && index < (int)ll_get_len(list)) {
        new_node->prev = node_to_move->prev;
        new_node->next = node_to_move;
        node_to_move->prev->next = new_node;
        node_to_move->prev = new_node;
    } else {
        new_node->next = node_to_move->next;
        new_node->prev = node_to_move;
        node_to_move->next->prev = new_node;
        node_to_move->next = new_node;
    }
}

bool ll_insert_node(llist_t *list, node_t *node, int index)
{
    if (list && !list->first) {
        list->first = node;
        node->next = node;
        node->prev = node;
        return true;
    }
    if (!ll_is_correct(list) || !node)
        return false;
    ll_add_node(list, node, index);
    list->first = index == 0 ? node : list->first;
    return true;
}

bool ll_insert_data(llist_t *list, void *data, int index)
{
    node_t *node = ll_create_node(data);

    if (!node)
        return false;
    return ll_insert_node(list, node, index);
}

bool ll_append_node(llist_t *list, node_t *node)
{
    return ll_insert_node(list, node, LL_ERROR);
}

bool ll_append_data(llist_t *list, void *data)
{
    return ll_insert_data(list, data, LL_ERROR);
}