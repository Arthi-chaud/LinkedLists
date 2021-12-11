/*
** EPITECH PROJECT, 2021
** LinkedLists
** File description:
** test_filter
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "linked_list.h"

static bool is_odd(void *data)
{
    return (unsigned long)data % 2 != 0;
}

static bool is_even(void *data)
{
    return !is_odd(data);
}

Test(ll_filter, empty_list)
{
    llist_t *list = ll_create_list();
    llist_t *filtered = ll_filter(list, is_even);

    cr_assert(ll_is_empty(filtered));
}

Test(ll_filter, filled_list_is_even)
{
    llist_t *list = ll_create_list();

    ll_append_data(list, (void *)3);
    ll_append_data(list, (void *)2);
    ll_append_data(list, (void *)1);
    llist_t *filtered = ll_filter(list, is_even);
    cr_assert_eq(ll_get_len(filtered), 1);
    cr_assert_eq(ll_get_data_by_index(filtered, 0), 2);
}

Test(ll_filter, filled_list_set_index)
{
    llist_t *list = ll_create_list();

    ll_append_data(list, (void *)3);
    ll_append_data(list, (void *)2);
    ll_append_data(list, (void *)1);
    llist_t *filtered = ll_filter(list, is_odd);
    cr_assert_eq(ll_get_len(filtered), 2);
    cr_assert_eq(ll_get_data_by_index(filtered, 0), 3);
    cr_assert_eq(ll_get_data_by_index(filtered, 1), 1);
}