#ifndef _libal_h
#define _libal_h
#include <stdlib.h>
#include <time.h>

#define PARENT(I) ((I-1)>>1)
#define LEFT(I) (((I)<<1)+1)
#define RIGHT(I) (((I)<<1)+2)
#define EXCHANGE(A,B) {int temp = A; A = B; B = temp;}
#define UNIFORM() (rand() / (RAND_MAX + 1.0))

static inline int Random(int p, int r) {
	srand(time(NULL));
	return p + (int)UNIFORM()*(r-p); 
	
}

int Max_heapify(int a[], int i, int heap_size);
int Build_max_heap(int *a, int size);
int Heapsort(int *a, int heap_size);
int Quicksort(int *a, int p, int r);	
int Partition(int *a, int p, int r);
int Hoare_partition(int *arr, int p, int r);
int Randomized_partition(int *a, int p, int r);
int Randomized_quicksort(int *a, int p, int r);
int Countingsort(int *arr, int *b, int k, int arr_length);
int Randomized_Select(int *arr, int p, int r,int i);

#endif
