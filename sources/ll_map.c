//
// Created by arthurjamet on 12/10/21.
//

#include "linked_list.h"

bool ll_map(llist_t *list, void *(*f) (void *data, int index, llist_t *list))
{
	size_t len = ll_get_len(list);
	node_t *current_node = NULL;

	if (ll_is_empty(list))
		return true;
	current_node = list->first;
	for (size_t i = 0; i < len; i++) {
		current_node->data = f(current_node->data, i, list);
		current_node = current_node->next;
	}
	return true;
}