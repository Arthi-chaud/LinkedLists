/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_has_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_has_node, has_node)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_has_node(list, node1), true);
    cr_assert_eq(ll_has_node(list, node2), true);
    cr_assert_eq(ll_has_node(list, node3), true);
}

Test(ll_has_node, node_null)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = NULL;

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_has_node(list, NULL), false);
}

Test(ll_has_node, node_not_in_list)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = NULL;

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    cr_assert_eq(ll_has_node(list, node3), 0);
}

Test(ll_has_node, empty_list)
{
    node_t *node1 = ll_create_node(NULL);
    llist_t *list = NULL;

    cr_assert_eq(ll_has_node(list, node1), false);
}