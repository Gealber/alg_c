#include "libal.c"
#include "minitest.h"
#include <stdio.h>

void test_maxheapify(void)
{
	START("maxheapify");
	int wanted[] = {16,14,10,8,7,9,3,2,4,1};
	int arr[] = {16,4,10,14,7,9,3,2,8,1};
	int arr_length = sizeof(arr)/ sizeof(int);
	assert(arr_length > 0);

	Max_heapify(arr,1, arr_length);
	check_arrs(arr,wanted,arr_length);
}
	
void test_build_maxheap(void)
{
	START("build_maxheap");
	int arr[] = {4,1,3,2,16,9,10,14,8,7};
	int wanted[] = {16,14,10,8,7,9,3,2,4,1};
	int arr_length = sizeof(arr)/sizeof(int);
	assert(arr_length > 0);

	Build_max_heap(arr,arr_length);
	check_arrs(arr,wanted,arr_length);
}

void test_heapsort(void)
{
	START("heapsort");
	int arr[] = {16,14,10,8,7,9,3,2,4,1};
	int wanted[] = {1,2,3,4,7,8,9,10,14,16};
	int heap_size = sizeof(arr)/sizeof(int);
	assert(heap_size > 0);

	Heapsort(arr,heap_size);
	check_arrs(arr, wanted,heap_size);
}

int main(int argc, char *argv[])
{
	test_maxheapify();
	test_build_maxheap();
	test_heapsort();
	return 0;
}
