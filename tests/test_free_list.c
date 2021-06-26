/*
** EPITECH PROJECT, 2020
** test_free.c
** File description:
** test_free
*/

#include "linked_list.h"
#include <stdlib.h>
#include <criterion/criterion.h>

Test(ll_free_list, list_no_free_data)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 0);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_free_list_and_data(list), true);
}

Test(ll_free_list, free_list_no_list)
{
    llist_t *list = NULL;

    cr_assert_eq(ll_free_list_and_data(list), false);
}

Test(ll_free_list, free_list_empty_list)
{
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_free_list_and_data(list), true);
}

Test(ll_free_list, list_w_free_data)
{
    void *data1 = (void *)strdup("DATA1");
    void *data2 = (void *)strdup("DATA2");
    void *data3 = (void *)strdup("DATA3");
    node_t *node1 = ll_create_node(data1);
    node_t *node2 = ll_create_node(data2);
    node_t *node3 = ll_create_node(data3);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 0);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_free_list(list), true);
}

Test(ll_free_list, list_w_error)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 0);
    ll_insert_node(list, node3, LL_ERROR);
    node2->prev = NULL;
    cr_assert_eq(ll_free_list(list), false);
}