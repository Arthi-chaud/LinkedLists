//
// Created by arthurjamet on 12/10/21.
//

#include "linked_list.h"

void *ll_foldl(llist_t *list, void *init, void *(*f)(void *value, void *data))
{
	size_t len = ll_get_len(list);
	node_t *current_node = NULL;
	void *res = init;

	if (ll_is_empty(list))
		return res;
	current_node = list->first;
	for (size_t i = 0; i < len; i++) {
		res = f(res, current_node->data);
		current_node = current_node->next;
	}
	return res;
}

void *ll_foldr(llist_t *list, void *init, void *(*f)(void *value, void *data))
{
	size_t len = ll_get_len(list);
	node_t *current_node = NULL;
	void *res = init;

	if (ll_is_empty(list))
		return res;
	current_node = list->first->prev;
	for (size_t i = 0; i < len; i++) {
		res = f(res, current_node->data);
		current_node = current_node->prev;
	}
	return res;
}