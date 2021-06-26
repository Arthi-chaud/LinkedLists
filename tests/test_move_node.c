/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_move_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_move_node, one_node_list)
{
    node_t *node = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node, 0);
    cr_assert_eq(ll_move_node(list, node, 0), true);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 1);
}

Test(ll_move_node, multiple_node_list)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    node_t *node4 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, 2);
    ll_insert_node(list, node4, 3);
    cr_assert_eq(ll_move_node(list, node3, 0), true);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 4);
    cr_assert_eq(list->first, node3);
    cr_assert_eq(node3->next, node1);
    cr_assert_eq(node3->prev, node4);
    cr_assert_eq(node1->next, node2);
    cr_assert_eq(node1->prev, node3);
}

Test(ll_move_node, exceptions)
{
    node_t *node = ll_create_node(NULL);
    llist_t *list = NULL;

    cr_assert_eq(ll_move_node(list, node, 3), false);
    ll_insert_node(list, node, 0);
    cr_assert_eq(ll_move_node(list, NULL, 3), false);
}

Test(ll_move_node, exception_node_not_in_list)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    node_t *node4 = ll_create_node(NULL);
    llist_t *list = NULL;

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, 2);
    cr_assert_eq(ll_move_node(list, node4, 0), false);
}