#ifndef _libal_h
#define _libal_h

#define PARENT(I) ((I-1)>>1)
#define LEFT(I) (((I)<<1)+1)
#define RIGHT(I) (((I)<<1)+2)
#define EXCHANGE(A,B) {int temp = A; A = B; B = temp;}

int Max_heapify(int a[], int i, int heap_size);
int Build_max_heap(int *a, int size);
int Heapsort(int *a, int heap_size);
	
#endif
