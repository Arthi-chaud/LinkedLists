/*
** EPITECH PROJECT, 2020
** test_revert.c
** File description:
** test_revert
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_revert, one_node)
{
    node_t *node = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_append_node(list, node);
    cr_assert_eq(ll_revert(list), true);
    cr_assert_eq(list->first, node);
    cr_assert_eq(node->prev, node);
    cr_assert_eq(node->next, node);
}

Test(ll_revert, empty_list)
{
    llist_t *list = NULL;

    cr_assert_eq(ll_revert(list), false);
}

Test(ll_revert, multiple_node)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_revert(list), true);
    cr_assert_eq(list->first, node3);
    cr_assert_eq(list->first->next, node2);
    cr_assert_eq(node2->next, node1);
    cr_assert_eq(node1->next, node3);
    cr_assert_eq(list->first->prev, node1);
    cr_assert_eq(node1->prev, node2);
    cr_assert_eq(node2->prev, node3);
}