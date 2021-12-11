/*
** EPITECH PROJECT, 2021
** LinkedLists
** File description:
** test_fold
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "linked_list.h"

static void *add(void *init, void *data)
{
    return (void *)((unsigned long)data + (unsigned long)init);
}

static void *divide(void *init, void *data)
{
    return (void *)((unsigned long)data / (unsigned long)init);
}

Test(ll_foldl, empty_list)
{
    llist_t *list = ll_create_list();
    void *init = "HEY";

    cr_assert_eq(ll_foldl(list, init, add), init);
}

Test(ll_foldr, empty_list)
{
    llist_t *list = ll_create_list();
    void *init = "HEY";

    cr_assert_eq(ll_foldr(list, init, add), init);
}

Test(ll_foldl, sum)
{
    llist_t *list = ll_create_list();
    void *init = (void *)1;

    ll_append_data(list, (void *)2);
    ll_append_data(list, (void *)3);
    ll_append_data(list, (void *)4);

    cr_assert_eq(ll_foldl(list, init, add), (void *)10);
}

Test(ll_foldl, divide)
{
    llist_t *list = ll_create_list();
    void *init = (void *)2;

    ll_append_data(list, (void *)10);
    ll_append_data(list, (void *)15);
    ll_append_data(list, (void *)27);

    cr_assert_eq(ll_foldl(list, init, divide), (void *)9);
}

Test(ll_foldr, divide)
{
    llist_t *list = ll_create_list();
    void *init = (void *)2;

    ll_append_data(list, (void *)33);
    ll_append_data(list, (void *)15);
    ll_append_data(list, (void *)10);

    cr_assert_eq(ll_foldr(list, init, divide), (void *)11);
}