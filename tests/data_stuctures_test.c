#include "minitest.h"
#include "stack.c"
#include "queue.c"
#include "list.c"
#include <assert.h>


static Stack *stack = NULL;
static Queue *queue = NULL;
static List *list = NULL;

char *test_stack_create(void)
{
	START("CREATE STACK");
	stack = Stack_create(sizeof(int), 5);
	mu_assert(stack != NULL,"Stack creation failed");
	mu_assert(stack->contents != NULL,"stack contents failed creation");
	mu_assert(stack->max == 5,"max elements differs");
	mu_assert(stack->top == 0,"position of top is not at the begning");
	mu_assert(stack->element_size == sizeof(int),"element_size differs");
	return NULL;

}

char *test_stack_pp(void)
{
	START("STACK PUSH POP");
	stack = Stack_create(sizeof(int), 5);
	int *val1 = calloc(1,stack->element_size);
	*val1 = 1;
	int *val2 = calloc(1,stack->element_size);
	*val2 = 2;

	Stack_push(stack,val1);
	Stack_push(stack,val2);
	mu_assert(stack->top > 1,"Got some errors trying to push");

	int *pop1 = Stack_pop(stack);
	mu_assert(pop1 != NULL, "Shouldn't get a NULL value");
	mu_assert(*pop1 == 2,"Pop value differs");
	free(pop1);

	int *pop2 = Stack_pop(stack);
	mu_assert(pop2 != NULL, "Shouldn't get a NULL value");
	mu_assert(*pop2 == 1, "Pop value differs");
	free(pop2);

	return NULL;
}

char *test_create_queue(void) 
{
	START("QUEUE CREATION");
	queue = Queue_create(sizeof(int),5);
	mu_assert(queue != NULL,"Stack creation failed");
	mu_assert(queue->contents != NULL,"stack contents failed creation");
	mu_assert(queue->max == 5,"max elements differs");
	mu_assert(queue->head == 0,"position of head is not at the begning");
	mu_assert(queue->tail == 0,"position of tail is not at the begining");
	mu_assert(stack->element_size == sizeof(int),"element_size differs");
	
	return NULL;
}

char *test_enqueue_dequeue(void)
{
	START("ENQUEUE_DEQUEUE_OPERATIONS");
	queue = Queue_create(sizeof(int), 5);
	int *val1 = calloc(1,queue->element_size);
	*val1 = 1;
	int *val2 = calloc(1,queue->element_size);
	*val2 = 2;
	
	Queue_enqueue(queue,val1);
	Queue_enqueue(queue,val2);
	mu_assert(queue->tail > 1,"Got some errors trying to push");

	int *pop1 = Queue_dequeue(queue);
	mu_assert(pop1 != NULL, "Shouldn't get a NULL value");
	mu_assert(*pop1 == 1,"Pop value differs");
	free(pop1);

	int *pop2 = Queue_dequeue(queue);
	mu_assert(pop2 != NULL, "Shouldn't get a NULL value");
	mu_assert(*pop2 == 2, "Pop value differs");
	free(pop2);
	
	return NULL;
}

char *test_linked_list_create(void)
{
	START("LINKED LIST CREATION");
	list = List_create();
	mu_assert(list != NULL, "Failure in creation if list");
	return NULL;
}

char *test_list_operations(void)
{
	START("LIST OPERATIONS");
	list = List_create();
	int *val1 = calloc(1,sizeof(int));
	*val1 = 1;
	int *val2 = calloc(1,sizeof(int));
	*val2 = 2;


	/*Inserting value*/
	List_insert(list,val1);
	List_insert(list,val2);
	
	/*Searching value*/
	ListNode *node = List_search(list,val2);
	mu_assert(node != NULL, "Nothing found");
	mu_assert(node->key == val2,"Failed to find element");
	
	/*Delete from list*/
	List_delete(list,node);
	node = List_search(list,val2);
	mu_assert(node == NULL, "Return something weird");
	return NULL;
}

int main(int argc, char *argv[])
{
	PASSED(test_stack_create());
	PASSED(test_stack_pp());
	PASSED(test_create_queue());
	PASSED(test_enqueue_dequeue());
	PASSED(test_linked_list_create());
	PASSED(test_list_operations());
	return 0;
}
