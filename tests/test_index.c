/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_index
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_get_node_by_index, test)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_get_node_by_index(list, 0), node1);
    cr_assert_eq(ll_get_node_by_index(list, 1), node2);
    cr_assert_eq(ll_get_node_by_index(list, LL_ERROR), node3);
}

Test(ll_get_data_node_by_index, test)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_get_data_by_index(list, 0), NULL);
    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_get_data_by_index(list, 0), NULL);
    cr_assert_eq(ll_get_data_by_index(list, 1), NULL);
    cr_assert_eq(ll_get_data_by_index(list, LL_ERROR), NULL);
}

Test(ll_get_node_by_index, no_list)
{
    llist_t *list = NULL;

    cr_assert_eq(ll_get_node_by_index(list, 0), NULL);
}

Test(ll_get_node_index, node_in_list)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_get_node_index(list, node1), 0);
    cr_assert_eq(ll_get_node_index(list, node2), 1);
    cr_assert_eq(ll_get_node_index(list, node3), 2);
}

Test(ll_get_node_index, special_cases)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = NULL;

    cr_assert_eq(ll_get_node_index(list, node2), LL_ERROR);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_get_node_index(list, node1), LL_ERROR);
    cr_assert_eq(ll_get_node_index(list, NULL), LL_ERROR);
    cr_assert_eq(ll_get_node_index(NULL, node2), LL_ERROR);
}