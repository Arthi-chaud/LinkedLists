/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_insert_list
*/

#include "linked_list.h"

static void ll_node_add_before(llist_t *src, node_t *node)
{
    node_t *tmp = NULL;
    node_t *src_first = src->first;

    src_first->prev->next = node;
    node->prev->next = src_first;
    tmp = src_first->prev;
    src_first->prev = node->prev;
    node->prev = tmp;
}

static void ll_node_add_after(llist_t *src, node_t *node)
{
    node_t *src_first = src->first;

    node->next->prev = src_first->prev;
    src_first->prev->next = node->next;
    node->next = src_first;
    src_first->prev = node;
}

bool ll_insert_list(llist_t *dest_list, llist_t *src_list, int index)
{
    node_t *node = NULL;

    if (!dest_list || !ll_is_correct(src_list))
        return false;
    if (dest_list->first == NULL) {
        dest_list->first = src_list->first;
        return true;
    }
    if (!ll_is_correct(dest_list))
        return false;
    node = ll_get_node_by_index(dest_list, index);
    if (0 <= index && index < (int)ll_get_len(dest_list))
        ll_node_add_before(src_list, node);
    else
        ll_node_add_after(src_list, node);
    if (index == 0 || node == dest_list->first)
        dest_list->first = src_list->first;
    return true;
}

bool ll_append_list(llist_t *dest_list, llist_t *src_list)
{
    return ll_insert_list(dest_list, src_list, LL_ERROR);
}