/*
** EPITECH PROJECT, 2020
** ll_from_array.c
** File description:
** ll_from_array
*/

#include "linked_list.h"

llist_t *ll_from_array(void **array)
{
    int array_len = 0;
    llist_t *list = ll_create_list();

    if (!array || !list)
        return NULL;
    if (!(*array))
        return NULL;
    for (int i = 0; array[i]; i++)
        array_len++;
    for (int i = 0; i < array_len; i++) {
        if (!ll_append_data(list, array[i]))
            return false;
    }
    return list;
}