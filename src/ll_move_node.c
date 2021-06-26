/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** ll_move_node
*/

#include "linked_list.h"

bool ll_move_node(llist_t *list, node_t *node, int index)
{
    if (!ll_is_correct(list) || !node)
        return false;
    if (!ll_has_node(list, node))
        return false;
    if (!ll_remove_node(list, node))
        return false;
    if (!ll_insert_node(list, node, index))
        return false;
    return true;
}