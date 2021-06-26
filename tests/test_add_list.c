/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_add_list
*/

#include "linked_list.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int print_function(void *data);

Test(ll_insert_list, deff_dest, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"a1");
    node_t *nodea2 = ll_create_node((void *)"a2");
    node_t *nodea3 = ll_create_node((void *)"a3");
    node_t *nodeb1 = ll_create_node((void *)"b1");
    node_t *nodeb2 = ll_create_node((void *)"b2");
    node_t *nodeb3 = ll_create_node((void *)"b3");
    llist_t *lista = ll_create_list();
    llist_t *listb = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    lista->first->prev = NULL;
    ll_insert_node(listb, nodeb1, LL_ERROR);
    ll_insert_node(listb, nodeb2, LL_ERROR);
    ll_insert_node(listb, nodeb3, LL_ERROR);
    cr_assert_eq(ll_append_list(lista, listb), false);
}

Test(ll_insert_list, ad_end_test, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"a1");
    node_t *nodea2 = ll_create_node((void *)"a2");
    node_t *nodea3 = ll_create_node((void *)"a3");
    node_t *nodeb1 = ll_create_node((void *)"b1");
    node_t *nodeb2 = ll_create_node((void *)"b2");
    node_t *nodeb3 = ll_create_node((void *)"b3");
    llist_t *lista = ll_create_list();
    llist_t *listb = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    ll_insert_node(listb, nodeb1, LL_ERROR);
    ll_insert_node(listb, nodeb2, LL_ERROR);
    ll_insert_node(listb, nodeb3, LL_ERROR);
    cr_assert_eq(ll_insert_list(lista, listb, LL_ERROR), true);
    cr_assert_eq(ll_get_len(lista), 6);
    cr_assert_eq(ll_is_correct(lista), 1);
    ll_print_data(lista, &print_function);
    cr_assert_stdout_eq_str("a1\na2\na3\nb1\nb2\nb3\n");
}

Test(ll_insert_list, add_middle_test, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"1");
    node_t *nodea2 = ll_create_node((void *)"2");
    node_t *nodea3 = ll_create_node((void *)"6");
    node_t *nodeb1 = ll_create_node((void *)"3");
    node_t *nodeb2 = ll_create_node((void *)"4");
    node_t *nodeb3 = ll_create_node((void *)"5");
    llist_t *lista = ll_create_list();
    llist_t *listb = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    ll_insert_node(listb, nodeb1, LL_ERROR);
    ll_insert_node(listb, nodeb2, LL_ERROR);
    ll_insert_node(listb, nodeb3, LL_ERROR);
    cr_assert_eq(ll_insert_list(lista, listb, 2), true);
    cr_assert_eq(ll_get_len(lista), 6);
    ll_print_data(lista, &print_function);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n6\n");
}

Test(ll_insert_list, add_middle_2_test, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"1");
    node_t *nodea2 = ll_create_node((void *)"5");
    node_t *nodea3 = ll_create_node((void *)"6");
    node_t *nodeb1 = ll_create_node((void *)"2");
    node_t *nodeb2 = ll_create_node((void *)"3");
    node_t *nodeb3 = ll_create_node((void *)"4");
    llist_t *lista = ll_create_list();
    llist_t *listb = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    ll_insert_node(listb, nodeb1, LL_ERROR);
    ll_insert_node(listb, nodeb2, LL_ERROR);
    ll_insert_node(listb, nodeb3, LL_ERROR);
    cr_assert_eq(ll_insert_list(lista, listb, 1), true);
    cr_assert_eq(ll_get_len(lista), 6);
    ll_print_data(lista, &print_function);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n6\n");
}

Test(ll_insert_list, add_begining_test, .init = cr_redirect_stdout)
{
    node_t *nodea1 = ll_create_node((void *)"4");
    node_t *nodea2 = ll_create_node((void *)"5");
    node_t *nodea3 = ll_create_node((void *)"6");
    node_t *nodeb1 = ll_create_node((void *)"1");
    node_t *nodeb2 = ll_create_node((void *)"2");
    node_t *nodeb3 = ll_create_node((void *)"3");
    llist_t *lista = ll_create_list();
    llist_t *listb = ll_create_list();

    ll_insert_node(lista, nodea1, LL_ERROR);
    ll_insert_node(lista, nodea2, LL_ERROR);
    ll_insert_node(lista, nodea3, LL_ERROR);
    ll_insert_node(listb, nodeb1, LL_ERROR);
    ll_insert_node(listb, nodeb2, LL_ERROR);
    ll_insert_node(listb, nodeb3, LL_ERROR);
    cr_assert_eq(ll_insert_list(lista, listb, 0), true);
    cr_assert_eq(ll_get_len(lista), 6);
    cr_assert_eq(lista->first, listb->first);
    ll_print_data(lista, &print_function);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n6\n");
}