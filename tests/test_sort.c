/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_sort
*/

#include "linked_list.h"
#include <criterion/criterion.h>

int cmp(void *data1, void *data2)
{
    return strcmp((const char *)data1, (const char *)data2);
}

int cmp2(void *data1, void *data2)
{
    return (int)(data1 - data2);
}

Test(ll_sort, test)
{
    node_t *node1 = ll_create_node((void *)"I_AM_3");
    node_t *node2 = ll_create_node((void *)"I_AM_2");
    node_t *node3 = ll_create_node((void *)"I_AM_1");
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, LL_ERROR);
    ll_insert_node(list, node2, LL_ERROR);
    ll_insert_node(list, node3, LL_ERROR);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 3);
    cr_assert_eq(ll_sort_asc(list, &cmp), true);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 3);
    cr_assert_eq(list->first, node3);
    cr_assert_eq(list->first->next, node2);
    cr_assert_eq(list->first->next->next, node1);
    cr_assert_eq(list->first->next->next->next, node3);
    cr_assert_eq(list->first->prev, node1);
    cr_assert_eq(list->first->prev->prev, node2);
    cr_assert_eq(list->first->prev->prev->prev, node3);
}

Test(ll_sort_asc_desc, test_long_list)
{
    node_t *node = NULL;
    llist_t *list = ll_create_list();

    for (void *i = (void *)'Z'; i >= (void *)'A'; i--) {
        node = ll_create_node((void *)i);
        ll_insert_node(list, node, LL_ERROR);
    }
    cr_assert_eq(ll_sort_asc(list, &cmp2), true);
    node = list->first;
    for (void *i = (void *)'A'; i <= (void *)'Z'; i++) {
        cr_assert_eq(node->data, i);
        node = node->next;
    }
    cr_assert_eq(ll_sort_desc(list, &cmp2), true);
    node = list->first;
    for (void *i = (void *)'Z'; i >= (void *)'A'; i--) {
        cr_assert_eq(node->data, i);
        node = node->next;
    }
}

Test(ll_sort, test_special_cases_node)
{
    node_t *node1 = ll_create_node((void *)"I_AM_3");
    node_t *node2 = ll_create_node((void *)"I_AM_2");
    llist_t *list = ll_create_list();

    cr_assert_eq(ll_sort_desc(NULL, &cmp2), false);
    cr_assert_eq(ll_sort_desc(list, &cmp2), true);
    ll_insert_node(list, node1, LL_ERROR);
    cr_assert_eq(ll_sort_asc(list, &cmp), true);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 1);
    ll_insert_node(list, node2, LL_ERROR);
    cr_assert_eq(ll_sort_asc(list, &cmp), true);
    cr_assert_eq(list->first, node2);
    cr_assert_eq(list->first->next, node1);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(ll_get_len(list), 2);
}