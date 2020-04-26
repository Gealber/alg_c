#include "queue.h"
#include <stdlib.h>

Queue *Queue_create(size_t element_size, size_t max)
{
	Queue *queue = malloc(sizeof(Queue));
	check_mem(queue);
	queue->max = max;
	check(queue->max > 0, "wrong max length");

	queue->contents = calloc(max, sizeof(void *));
	check_mem(queue->contents);

	queue->head = 0;
	queue->tail = 0;
	queue->element_size = element_size;
	return queue;
error:
	if(queue) free(queue);
	return NULL;
}

void *Queue_dequeue(Queue *queue)
{
	void *x = queue->contents[queue->head];
	if(queue->head == queue->max) {
		queue->head = 0;
	} else {
		queue->head++;
	}
	return x;
}

int Queue_enqueue(Queue *queue, void *element)
{
	queue->contents[queue->tail] = element;
	if(queue->tail == queue->max) {
		queue->tail = 0;
	} else {
		queue->tail++;
	}
	return 0;
}
