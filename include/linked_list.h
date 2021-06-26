/*
** EPITECH PROJECT, 2020
** linked_list
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stddef.h>
#include <stdbool.h>

#define LL_ERROR (-1)

typedef struct s_node {
    struct s_node *prev;
    void *data;
    struct s_node *next;
}node_t;

typedef struct s_linked_list
{
    struct s_node *first;
}llist_t;


//-- INSERT FUNCTIONS --//

//! @brief Creates a node containing data, and inserting node at index in list
bool ll_insert_data(llist_t *list, void *data, int index);

//! @brief Creates a node containing data, and inserting node at end in list
bool ll_append_data(llist_t *list, void *data);

//! @brief Inserts node at index in list
bool ll_insert_node(llist_t *list, node_t *node, int index);

//! @brief Inserts node at end in list
bool ll_append_node(llist_t *list, node_t *node);

//! @brief Inserts src_list in dest_list at index
bool ll_insert_list(llist_t *dest_list, llist_t *src_list, int index);

//! @brief Add src_list at end of dest_list
bool ll_append_list(llist_t *dest_list, llist_t *src_list);



//-- SORTING FUNCTIONS --//

//! @brief Sorts list in ascendant order, using cmp as value comparator
bool ll_sort_asc(llist_t *list, int (*cmp)(void *data1, void *data2));

//! @brief Sorts list in descendant order, using cmp as value comparator
bool ll_sort_desc(llist_t *list, int (*cmp)(void *data1, void *data2));



//-- ARRAY CONVERSION --//

//! @brief Creates an array from values in list.
//! @info The values are not duplicated
void **ll_to_array(llist_t *list);

//! @brief Creates linked list from array.
//! @info The values are not duplicated
llist_t *ll_from_array(void **data);



//-- PROPERTIES --//

//! @brief Returns length of list.
//! @return If an error occurs, LL_ERROR is returned
size_t ll_get_len(llist_t *list);

//! @brief Returns true if list is empty (first == NULL).
//! @return If an error occurs, false is returned
bool ll_is_empty(llist_t *list);

//! @brief Returns true if list contains node.
//! @return If an error occurs, false is returned
bool ll_has_node(llist_t *list, node_t *node);

//! @brief Check if a list is correctly formed
bool ll_is_correct(llist_t *list);

//! @brief Display data from each node of list using print_function
bool ll_print_data(llist_t *list, int (*print_function)(void *data));



//-- INSERTION FUNCTIONS --//

//! @brief Returns true if node was moved successfully at index.
//! @return If an errors occurs, false is returned
bool ll_move_node(llist_t *list, node_t *node, int index);

//! @brief Returns true if node was removed successfullyfrom list.
//! @return If an errors occurs, false is returned
bool ll_remove_node(llist_t *list, node_t *node);

//! @brief Returns true if node at index removed successfullyfrom list.
//! @return If an errors occurs, false is returned
bool ll_remove_node_at_index(llist_t *list, int index);

//! @brief Returns true if the node containing data was successfully removed
//! @brief Returns false if data not in list.
//! @brief Only working for pointers
bool ll_remove_node_by_data(llist_t *list, void *data);

//! @brief Returns true list was reversed successfully.
//! @return If an errors occurs, false is returned
bool ll_revert(llist_t *list);



//-- INDEX RELATED FUNCTIONS --//

//! @brief Returns pointer to node at index. Index can be negative.
//! @return If an error occurs, NULL is returned.
node_t *ll_get_node_by_index(llist_t *list, int index);

//! @brief Returns pointer to data from node at index. Index can be negative.
//! @return If an error occurs, NULL is returned.
void *ll_get_data_by_index(llist_t *list, int index);

//! @brief Returns index of node in list.
//! @return If an error occurs, LL_ERROR is returned
size_t ll_get_node_index(llist_t *list, node_t *node);



//-- CREATION FUNCTION --//

//! @brief Creates a node, with data. Prev/Next fields are set tot NULL
node_t *ll_create_node(void *data);

//! @brief Creates empty list. 'first' firled is set tot NULL
llist_t *ll_create_list(void);

//! @brief Creates list with one node, containing data.
llist_t *ll_one_node(void *data);



//-- DESTROYING FUNCTION --//

//! @brief Returns true if list was successfully destroyed
//! @info the head is freed
bool ll_free_list(llist_t *list);

//! @brief Returns true if list and related data was successfully destroyed
//! @info the head is freed
bool ll_free_list_and_data(llist_t *list);

//! @brief Returns true if node was successfully destroyed
bool ll_free_node(node_t **node);

//! @brief Returns true if node and data was successfully destroyed
bool ll_free_node_and_data(node_t **node);

#endif /* !LINKED_LIST_H_ */
