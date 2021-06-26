/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_free_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_free_node, ok)
{
    node_t *node = ll_create_node(NULL);

    cr_assert_eq(ll_free_node(&node), true);
    cr_assert_null(node);
}

Test(ll_free_node, null)
{
    node_t *node = NULL;

    cr_assert_eq(ll_free_node(&node), false);
    cr_assert_null(node);
}

Test(ll_free_node, no_ptr)
{
    cr_assert_eq(ll_free_node(NULL), false);
}