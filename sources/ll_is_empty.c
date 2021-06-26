/*
** EPITECH PROJECT, 2021
** Samples
** File description:
** ll_empty
*/

#include "linked_list.h"

bool ll_is_empty(llist_t *list)
{
    if (!list)
        return false;
    return ll_get_len(list) == 0;
}