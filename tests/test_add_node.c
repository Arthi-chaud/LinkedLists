/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_add_node
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_insert_node, no_list)
{
    void *data = (void *)"I_AM_DATA";
    node_t *node = ll_create_node(data);
    llist_t *list = NULL;

    cr_assert_eq(ll_insert_node(list, node, 0), false);
    list = ll_create_list();
    cr_assert_eq(ll_insert_node(list, node, 0), true);
    cr_assert_eq(list->first, node);
    cr_assert_eq(node, node->next);
    cr_assert_eq(node, node->prev);
    cr_assert_eq(list->first->data, data);
}

Test(ll_insert_node, add_node_to_list)
{
    node_t *node1 = ll_create_node((void *)"I_AM_DATA");
    node_t *node2 = ll_create_node((void *)"I_AM_SECOND");
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_insert_node(list, node1, 0), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(ll_insert_node(list, node2, 0), true);
    cr_assert_eq(list->first, node2);
    cr_assert_eq(list->first->prev, node1);
    cr_assert_eq(list->first->next, node1);
    cr_assert_eq(node1->prev, node2);
    cr_assert_eq(node1->next, node2);
    cr_assert_eq(ll_insert_node(list, node3, LL_ERROR), true);
    cr_assert_eq(list->first, node2);
    cr_assert_eq(list->first->prev, node3);
    cr_assert_eq(node3->next, node2);
    cr_assert_eq(node3->prev, node1);
    cr_assert_eq(node1->next, node3);
    node2->next = NULL;
    cr_assert_eq(ll_insert_node(list, node3, 0), false);
}

Test(ll_insert_node, add_node_to_end_list)
{
    node_t *node1 = ll_create_node((void *)"I_AM_DATA");
    node_t *node2 = ll_create_node((void *)"I_AM_SECOND");
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_insert_node(list, node1, 0), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(ll_insert_node(list, node2, 1), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(list->first->prev, node2);
    cr_assert_eq(list->first->next, node2);
    cr_assert_eq(node2->prev, node1);
    cr_assert_eq(node2->next, node1);
    cr_assert_eq(ll_insert_node(list, node3, LL_ERROR), true);
    cr_assert_eq(list->first->prev, node3);
    cr_assert_eq(node3->next, node1);
    cr_assert_eq(node3->prev, node2);
    cr_assert_eq(node2->next, node3);
    node2->next = NULL;
}

Test(ll_insert_node, add_node_to_end_list_using_neg)
{
    node_t *node1 = ll_create_node((void *)"I_AM_DATA");
    node_t *node2 = ll_create_node((void *)"I_AM_SECOND");
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_insert_node(list, node1, 0), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(ll_insert_node(list, node2, LL_ERROR), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(list->first->prev, node2);
    cr_assert_eq(list->first->next, node2);
    cr_assert_eq(node2->prev, node1);
    cr_assert_eq(node2->next, node1);
    cr_assert_eq(ll_insert_node(list, node3, LL_ERROR), true);
    cr_assert_eq(list->first->prev, node3);
    cr_assert_eq(node3->next, node1);
    cr_assert_eq(node3->prev, node2);
    cr_assert_eq(node2->next, node3);
}

Test(ll_insert_node, index_stricty_superior_to_len)
{
    node_t *node1 = ll_create_node((void *)"I_AM_DATA");
    node_t *node2 = ll_create_node((void *)"I_AM_SECOND");
    node_t *node3 = ll_create_node(NULL);
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_insert_node(list, node1, 10), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(ll_insert_node(list, node2, 100), true);
    cr_assert_eq(list->first, node1);
    cr_assert_eq(list->first->prev, node2);
    cr_assert_eq(list->first->next, node2);
    cr_assert_eq(node2->prev, node1);
    cr_assert_eq(node2->next, node1);
    cr_assert_eq(ll_insert_node(list, node3, 3), true);
    cr_assert_eq(list->first->prev, node3);
    cr_assert_eq(node3->next, node1);
    cr_assert_eq(node3->prev, node2);
    cr_assert_eq(node2->next, node3);
}