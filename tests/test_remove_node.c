/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_remove_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_remove_node, elem_w_3node)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_remove_node(list, node1), true);
    cr_assert_eq(list->first, node2);
    cr_assert_eq(node2->prev, node3);
    cr_assert_eq(node3->next, node2);
    cr_assert_null(node1->next);
    cr_assert_null(node1->prev);
}

Test(ll_remove_node, one_node_list)
{
    node_t *node1 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    cr_assert_eq(ll_remove_node(list, node1), true);
    cr_assert_null(list->first);
}

Test(ll_remove_node, no_node)
{
    llist_t *list = NULL;

    cr_assert_eq(ll_remove_node(list, NULL), false);
}

Test(ll_remove_node, node_not_in_list)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node2, 0);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_remove_node(list, node1), false);
}

Test(ll_remove_node, ptr_to_null)
{
    node_t *node = ll_create_node(NULL);

    cr_assert_eq(ll_remove_node(NULL, node), false);
}