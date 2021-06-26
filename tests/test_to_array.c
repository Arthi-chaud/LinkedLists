/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_to_array
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_to_array, normal_test)
{
    char **word_array = NULL;
    void *data1 = (void *)"HELLO";
    void *data2 = (void *)"I\'M";
    void *data3 = (void *)"MARVIN";
    node_t *node1 = ll_create_node(data1);
    node_t *node2 = ll_create_node(data2);
    node_t *node3 = ll_create_node(data3);
    llist_t *list = ll_create_list();

    ll_insert_node(list, node1, 0);
    ll_insert_node(list, node2, 1);
    ll_insert_node(list, node3, LL_ERROR);
    word_array = (char **)ll_to_array(list);
    cr_assert_not_null(word_array);
    cr_assert_eq(word_array[0], data1);
    cr_assert_eq(word_array[1], data2);
    cr_assert_eq(word_array[2], data3);
    cr_assert_null(word_array[3]);
}

Test(ll_to_array, empty_list)
{
    llist_t *list = NULL;
    char **word_array = (char **)ll_to_array(list);
    cr_assert_null(word_array);
}