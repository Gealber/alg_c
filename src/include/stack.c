#include "stack.h"
#include <stdlib.h>

Stack *Stack_create(size_t element_size, size_t max)
{
	Stack *stack = malloc(sizeof(Stack));
	check_mem(stack);
	stack->max = max;
	check(stack->max > 0,"wrong max length on initial size");

	stack->contents = calloc(max,sizeof(void *));
	check_mem(stack->contents);

	stack->top = 0;
	stack->element_size = element_size;
	return stack;
error:
	if(stack) free(stack);
	return NULL;
}

int Stack_empty(Stack *stack)
{
	if (stack->top == 0)
		return 1;
	return 0;
}

int Stack_push(Stack *stack, void *element)
{
	stack->top++;
	stack->contents[stack->top] = element;
	return 0;
}

void *Stack_pop(Stack *stack)
{
	check(stack->top - 1 >= 0,"Attempt to pop from an empty array.");
	void *element = stack->contents[stack->top];
	stack->contents[stack->top] = NULL;
	stack->top = stack->top - 1;
	return element;
error:
	return NULL;
}
