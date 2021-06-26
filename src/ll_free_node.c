/*
** EPITECH PROJECT, 2020
** destroy_node
** File description:
** ll_destroy_node
*/

#include "linked_list.h"
#include <stdlib.h>

bool ll_free_node(node_t **node)
{
    if (!node)
        return false;
    if (!(*node))
        return false;
    free(*node);
    *node = NULL;
    return true;
}

bool ll_free_node_and_data(node_t **node)
{
    if (!node)
        return false;
    if (!(*node))
        return false;
    if ((*node)->data) {
        free((*node)->data);
        (*node)->data = NULL;
    }
    return ll_free_node(node);
}