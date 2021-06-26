/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_print_data
*/

#include "linked_list.h"
#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int print_function(void *data)
{
    printf("%s\n", (char *)data);
    fflush(stdout);
    return false;
}

Test(ll_print_data, test, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"I_AM_a1");
    node_t *nodea2 = ll_create_node((void *)"I_AM_a2");
    node_t *nodea3 = ll_create_node((void *)"I_AM_a3");
    llist_t *lista = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    ll_print_data(lista, &print_function);
    cr_assert_stdout_eq_str("I_AM_a1\nI_AM_a2\nI_AM_a3\n");
}

Test(ll_print_data, test_error)
{
    llist_t *a = NULL;
    cr_assert_eq(ll_print_data(a, &print_function), false);
}