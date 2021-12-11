/*
** EPITECH PROJECT, 2021
** LinkedLists
** File description:
** test_map
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "linked_list.h"

static void *add_one(void *data, int index, llist_t *list)
{
    (void)index;
    (void)list;
    return (void *)(data + 1);
}

static void *set_index(void *data, int index, llist_t *list)
{
    (void)data;
    (void)list;
    return (void *)(unsigned long)index;
}

Test(ll_map, empty_list)
{
    llist_t *list = ll_create_list();

    cr_assert(ll_map(list, add_one));
}

Test(ll_map, filled_list_addition)
{
    llist_t *list = ll_create_list();

    ll_append_data(list, (void *)3);
    ll_append_data(list, (void *)2);
    ll_append_data(list, (void *)1);
    ll_map(list, add_one);
    cr_assert_eq(ll_get_data_by_index(list, 0), 4);
    cr_assert_eq(ll_get_data_by_index(list, 1), 3);
    cr_assert_eq(ll_get_data_by_index(list, 2), 2);
}

Test(ll_map, filled_list_set_index)
{
    llist_t *list = ll_create_list();

    ll_append_data(list, (void *)3);
    ll_append_data(list, (void *)2);
    ll_append_data(list, (void *)1);
    ll_map(list, set_index);
    cr_assert_eq(ll_get_data_by_index(list, 0), 0);
    cr_assert_eq(ll_get_data_by_index(list, 1), 1);
    cr_assert_eq(ll_get_data_by_index(list, 2), 2);
}