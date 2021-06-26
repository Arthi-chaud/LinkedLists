/*
** EPITECH PROJECT, 2020
** create_node.c
** File description:
** ll_create_node
*/

#include "linked_list.h"
#include <stdlib.h>

node_t *ll_create_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}