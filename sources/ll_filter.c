//
// Created by arthurjamet on 12/10/21.
//

#include "linked_list.h"

llist_t *ll_filter(llist_t *list, bool (*filter) (void *data))
{
	llist_t *filtered = ll_create_list();
	size_t len = ll_get_len(list);
	node_t *currrent_node = NULL;

	if (filtered == NULL)
		return NULL;
	currrent_node = list->first;
	for (size_t i = 0; i < len; i++) {
		if (filter(currrent_node->data))
			ll_append_data(filtered, currrent_node->data);
		currrent_node = currrent_node->next;
	}
	return filtered;
}