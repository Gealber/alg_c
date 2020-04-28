#include "list.h"
#include "dbg.h"
#include <stdlib.h>

List *List_create(void)
{
	return calloc(1,sizeof(List));
}

ListNode *List_search(List *list, void *key)
{
	ListNode *x = list->head;
	while(x != NULL && x->key != key) {
		x = x->next;
	}
	return x;
}

void List_insert(List *list, void *value)
{
	ListNode *node = calloc(1,sizeof(ListNode));
	check_mem(node);

	node->key = value;
	node->next = list->head;
	if(list->head != NULL) {
		list->head->prev = node;
	}
	list->head = node;
	node->prev = NULL;
	list->count++;
error:
	return;
}

void List_delete(List *list, ListNode *node)
{
	if(node->prev != NULL) {
		node->prev = node->next;
	} else {
		//this case is when you remove the first element
		list->head = node->next;
	}

	if(node->next != NULL) {
		node->next->prev = node->prev;
	}
}

