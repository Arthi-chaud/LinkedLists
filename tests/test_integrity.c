/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_integrity
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_is_correct, ok)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_append_data(list, node1);
    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node1;
    cr_assert_eq(ll_is_correct(list), 1);
}

Test(ll_is_correct, incorrect)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_append_node(list, node1);
    node1->prev = node3;
    node1->next = node2;
    node2->prev = node1;
    node2->next = NULL;
    node3->prev = node2;
    node3->next = node1;
    cr_assert_eq(ll_is_correct(list), false);
}

Test(ll_is_correct, incorrect_2)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_append_node(list, node1);
    node1->prev = node3;
    node1->next = NULL;
    node2->prev = node1;
    node2->next = NULL;
    node3->prev = node2;
    node3->next = node1;
    cr_assert_eq(ll_is_correct(list), 0);
}

Test(ll_is_correct, incorrect_3)
{
    node_t *node1 = ll_create_node(NULL);
    node_t *node2 = ll_create_node(NULL);
    node_t *node3 = ll_create_node(NULL);
    node_t *node4 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    ll_append_node(list, node1);
    node1->prev = node4;
    node1->next = node2;
    node2->prev = node1;
    node2->next = NULL;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = NULL;
    node4->next = node1;
    cr_assert_eq(ll_is_correct(list), 0);
}

Test(ll_is_correct, null_ptr)
{
    cr_assert_eq(ll_is_correct(NULL), 0);
}