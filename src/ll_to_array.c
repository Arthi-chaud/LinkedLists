/*
** EPITECH PROJECT, 2020
** ll_to_array.c
** File description:
** ll_to_array
*/

#include "linked_list.h"
#include <stdlib.h>

void **ll_to_array(llist_t *list)
{
    node_t *cursor = NULL;
    void **array = NULL;
    int list_len = 0;

    if (!ll_is_correct(list))
        return NULL;
    list_len = ll_get_len(list);
    if (list_len < 0)
        return NULL;
    array = malloc(sizeof(void *) * (list_len + 1));
    if (!array)
        return NULL;
    for (int i = 0; i < list_len; i++) {
        cursor = ll_get_node_by_index(list, i);
        array[i] = cursor->data;
    }
    array[list_len] = NULL;
    return array;
}