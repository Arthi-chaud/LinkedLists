/*
** EPITECH PROJECT, 2020
** create_node.c
** File description:
** ll_create_node
*/

#include "linked_list.h"
#include <stdlib.h>

llist_t *ll_create_list(void)
{
    llist_t *list = malloc(sizeof(llist_t));

    if (!list)
        return NULL;
    list->first = NULL;
    return list;
}