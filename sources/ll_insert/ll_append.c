/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_insert_node
*/

#include "linked_list.h"

bool ll_append_node(llist_t *list, node_t *node)
{
    return ll_insert_node(list, node, -1);
}

bool ll_append_data(llist_t *list, void *data)
{
    return ll_insert_data(list, data, -1);
}

bool ll_append_list(llist_t *dest_list, llist_t *src_list)
{
    return ll_insert_list(dest_list, src_list, -1);
}