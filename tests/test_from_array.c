/*
** EPITECH PROJECT, 2020
** Samples
** File description:
** test_from_array
*/

#include "linked_list.h"
#include <criterion/criterion.h>

Test(ll_from_array, normal_test)
{
    char *word_array[] = {"HELLO", "I", "AM", "MARVIN", NULL};
    void **array = (void **) word_array;
    llist_t *list = ll_from_array(array);

    cr_assert_not_null(list);
    cr_assert_eq(ll_is_correct(list), 1);
    cr_assert_eq(list->first->data, word_array[0]);
    cr_assert_eq(list->first->next->data, array[1]);
    cr_assert_eq(list->first->next->next->data, array[2]);
    cr_assert_eq(list->first->prev->data, array[3]);
    cr_assert_eq(list->first->prev->prev->data, array[2]);
}

Test(ll_from_array, null_ptr)
{
    llist_t *list = ll_from_array(NULL);

    cr_assert_null(list);
}

Test(ll_from_array, ptr_to_empty_array)
{
    char *word_array[] = {NULL};
    void **array = (void **) word_array;
    llist_t *list = ll_from_array(array);

    cr_assert_null(list);
}