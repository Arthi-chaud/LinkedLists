/*
** EPITECH PROJECT, 2021
** LinkedLists
** File description:
** ll_push_front
*/

#include "linked_list.h"

bool ll_push_front_node(llist_t *list, node_t *node)
{
    return ll_insert_node(list, node, 0);
}

bool ll_push_front_data(llist_t *list, void *data)
{
    return ll_insert_data(list, data, 0);
}

bool ll_push_front_list(llist_t *dest_list, llist_t *src_list)
{
    return ll_insert_list(dest_list, src_list, 0);
}