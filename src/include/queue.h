#ifndef _queue_h
#define _queue_h
#include "dbg.h"

typedef struct Queue {
	void **contents;
	int head;
	int tail;
	int max;
	size_t element_size;
} Queue;

Queue *Queue_create(size_t element_size, size_t max);
void Queue_destroy(Queue *queue);
void *Queue_dequeue(Queue *queue);
int Queue_enqueue(Queue *queue, void *element);
#endif
