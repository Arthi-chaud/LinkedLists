/*
** EPITECH PROJECT, 2021
** LinkedLists
** File description:
** ll_insert_data
*/

#include "linked_list.h"

bool ll_insert_data(llist_t *list, void *data, int index)
{
    node_t *node = ll_create_node(data);

    if (!node)
        return false;
    return ll_insert_node(list, node, index);
}