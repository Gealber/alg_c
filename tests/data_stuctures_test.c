#include "minitest.h"
#include "stack.c"
#include <assert.h>


static Stack *stack = NULL;

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

int main(int argc, char *argv[])
{
	PASSED(test_stack_create());
	PASSED(test_stack_pp());
	return 0;
}
