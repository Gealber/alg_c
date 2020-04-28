#ifndef _list_h
#define _list_h

typedef struct ListNode {
	struct ListNode *prev;
	struct ListNode *next;
	void *key;
} ListNode;

typedef struct List {
	int count;
	ListNode *head;
	ListNode *tail;
} List;

List *List_create(void);
ListNode *List_search(List *list, void *key);
void List_insert(List *list, void *value);
void List_delete(List *list, ListNode *node);
#endif
