/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_one_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_one_node, with_list)
{
    llist_t *onl = ll_one_node((void *)"HELLO");

    cr_assert_not_null(onl);
    cr_assert_str_eq((char *)onl->first->data, "HELLO");
    cr_assert_str_eq("HELLO", (char *)onl->first->prev->data);
    cr_assert_str_eq("HELLO", (char *)onl->first->next->data);
}
