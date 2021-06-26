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

//! @brief Data structure representing a linked-list's node
typedef struct s_node {
    //! @brief A pointer to the previous node
    struct s_node *prev;
    //! @brief The data-holding field
    void *data;
    //! @brief A pointer to the next node
    struct s_node *next;
} node_t;

//! @brief Data structure representing a linked-list's head

typedef struct s_linked_list
{
    //! @brief A pointer to the first node of the list
    //! @note if first equals NULL, the list is considered as empty
    struct s_node *first;
} llist_t;


//-- INSERT FUNCTIONS --//

//! @brief Creates a node containing data, and inserting node at index in list
//! @return false if an error occurs, or true in success
bool ll_insert_data(llist_t *list, void *data, int index);

//! @brief Creates a node containing data, and inserting node at end in list
//! @return false if an error occurs, or true in success
bool ll_append_data(llist_t *list, void *data);

//! @brief Creates a node containing data, and inserting node at the front of the list
//! @return false if an error occurs, or true in success
bool ll_push_front_data(llist_t *list, void *data);

//! @brief Inserts node at index in list
//! @return false if an error occurs, or true in success
bool ll_insert_node(llist_t *list, node_t *node, int index);

//! @brief Inserts node at end in list
//! @return false if an error occurs, or true in success
bool ll_append_node(llist_t *list, node_t *node);

//! @brief Inserts node at the front of the list
//! @return false if an error occurs, or true in success
bool ll_push_front_node(llist_t *list, node_t *node);

//! @brief Inserts src_list in dest_list at index
//! @return false if an error occurs, or true in success
bool ll_insert_list(llist_t *dest_list, llist_t *src_list, int index);

//! @brief Append src_list to the end dest_list
//! @return false if an error occurs, or true in success
bool ll_append_list(llist_t *dest_list, llist_t *src_list);

//! @brief Inserts src_list at the front of dest_list
//! @return false if an error occurs, or true in success
bool ll_push_front_list(llist_t *dest_list, llist_t *src_list);



//-- SORTING FUNCTIONS --//

//! @brief Sorts list in ascendant order, using cmp as value comparator
//! @return false if an error occurs, or true in success
bool ll_sort_asc(llist_t *list, int (*cmp)(void *data1, void *data2));

//! @brief Sorts list in descendant order, using cmp as value comparator
//! @return false if an error occurs, or true in success
bool ll_sort_desc(llist_t *list, int (*cmp)(void *data1, void *data2));



//-- ARRAY CONVERSION --//

//! @brief Creates an array from values in list.
//! @note The values are not duplicated
//! @return A pointer to a 2D array, or NULL on error
void **ll_to_array(llist_t *list);

//! @brief Creates linked list from array.
//! @note The values are not duplicated
//! @return A pointer to a list's head, or NULL on error
llist_t *ll_from_array(void **data);



//-- PROPERTIES --//

//! @brief Returns length of list.
//! @return If an error occurs (invalid list, for example), LL_ERROR is returned
size_t ll_get_len(llist_t *list);

//! @brief Returns true if list is empty (first == NULL).
//! @return false if an error occurs, or true in success
bool ll_is_empty(llist_t *list);

//! @brief Returns true if list contains node.
//! @return false if an error occurs, or true in success
bool ll_has_node(llist_t *list, node_t *node);

//! @brief Check if a list is correctly formed
bool ll_is_correct(llist_t *list);

//! @brief Display data from each node of list using print_function
//! @return false if an error occurs, or true in success
bool ll_print_data(llist_t *list, int (*print_function)(void *data));



//-- INSERTION FUNCTIONS --//

//! @brief Returns true if node was moved successfully at index.
//! @return false if an error occurs, or true in success
bool ll_move_node(llist_t *list, node_t *node, int index);

//! @brief Returns true if node was removed successfullyfrom list.
//! @return false if an error occurs, or true in success
bool ll_remove_node(llist_t *list, node_t *node);

//! @brief Returns true if node at index removed successfullyfrom list.
//! @return false if an error occurs, or true in success
bool ll_remove_node_at_index(llist_t *list, int index);

//! @brief Returns true if the node containing data was successfully removed
//! @return false if an error occurs, or true in success
//! @param cmp a function, which returns true if the data are equal 
bool ll_remove_node_by_data(llist_t *list, void *data, bool (*cmp)(void *, void *));

//! @brief Returns true list was reversed successfully.
//! @return false if an error occurs, or true in success
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

//! @brief Creates a node, with data. Prev/Next fields are set to NULL
//! @return A pointer to a node, or NULL if an error occurs.
node_t *ll_create_node(void *data);

//! @brief Creates empty list.'first' field is set to NULL
//! @return A pointer to an "empty" list, or NULL if an error occurs.
llist_t *ll_create_list(void);

//! @brief Creates list with one node, containing data.
//! @return A pointer to a list, or NULL if an error occurs.
llist_t *ll_one_node(void *data);


//-- DESTROYING FUNCTION --//

//! @brief Returns true if list was successfully destroyed
//! @warning the head is freed
bool ll_free_list(llist_t *list);

//! @brief Returns true if list and related data was successfully destroyed
//! @warning the head is freed
bool ll_free_list_and_data(llist_t *list);

//! @brief Free a node (the data structure), but not the hold data
//! @return false if an error occurs, or true in success
bool ll_free_node(node_t **node);

//! @brief Free a node (the data structure), AND the hold data
//! @return false if an error occurs, or true in success
bool ll_free_node_and_data(node_t **node);

#endif /* !LINKED_LIST_H_ */
