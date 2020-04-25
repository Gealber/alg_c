#ifndef _stack_h
#define _stack_h
#include "dbg.h"

typedef struct Stack {
	void **contents;
	int top;
	int max;
	size_t element_size;
} Stack;

Stack *Stack_create(size_t element_size, size_t max);
void Stack_destroy(Stack *stack);
void *Stack_pop(Stack *stack);
int Stack_empty(Stack *stack);
int Stack_push(Stack *stack, void *element);

#endif
