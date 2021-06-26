/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_create_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_create_node, without_data)
{
    node_t *node = ll_create_node(NULL);

    cr_assert_not_null(node);
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
    cr_assert_null(node->data);
}

Test(ll_create_node, with_data)
{
    char *str = "HELLO";
    node_t *node = ll_create_node((void *)str);

    cr_assert_not_null(node);
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
    cr_assert_str_eq((char *)node->data, "HELLO");
    cr_assert_eq(node->data, str);
}