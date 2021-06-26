/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_len
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_get_len, ok)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node1;
    cr_assert_eq(ll_get_len(list), 3);
}

Test(ll_get_len, incorrect)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_is_empty(list), true);
    ll_insert_node(list, node1, 0);
    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = NULL;
    node3->prev = node2;
    node3->next = node1;
    cr_assert_eq(ll_get_len(list), LL_ERROR);
}

Test(ll_get_len, null_ptr)
{
    cr_assert_eq(ll_get_len(NULL), LL_ERROR);
}

Test(ll_is_empty, null_ptr)
{
    cr_assert_eq(ll_is_empty(NULL), false);
}