/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_free_node
*/

#include <stdio.h>
#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_free_node_and_data, ok)
{
    void *data = (void *)strdup("OK");
    node_t *node = ll_create_node(data);

    cr_assert_eq(ll_free_node_and_data(&node), true);
    cr_assert_null(node);
}

Test(ll_free_node_and_data, ok_no_data)
{
    node_t *node = ll_create_node(NULL);

    cr_assert_eq(ll_free_node_and_data(&node), true);
    cr_assert_null(node);
}

Test(ll_free_node_and_data, null)
{
    node_t *node = NULL;

    cr_assert_eq(ll_free_node_and_data(&node), false);
    cr_assert_null(node);
}

Test(ll_free_node_and_data, no_ptr)
{
    cr_assert_eq(ll_free_node_and_data(NULL), false);
}