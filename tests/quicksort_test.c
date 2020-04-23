#include "libal.c"
#include "minitest.h"


void test_quicksort(void)
{
	START("QUICKSORT");
	int arr[] = {2,8,7,1,3,5,6,4};
	int wanted[] = {1,2,3,4,5,6,7,8};
	int arr_length = sizeof(arr)/ sizeof(int);
	assert(arr_length > 0);

	Quicksort(arr,0,arr_length-1);
	check_arrs(arr,wanted,arr_length);
}

void test_partition(void)
{
	START("PARTITION_QUICKSORT");
	int arr[] = {2,8,7,1,3,5,6,4};
	int wanted[] = {2,1,3,4,7,5,6,8};
	int arr_length = sizeof(arr)/sizeof(int);
	assert(arr_length > 0);
	
	Partition(arr, 0, 7);
	check_arrs(arr, wanted,arr_length);
}

int main(int argc, char *argv[])
{
	test_partition();
	test_quicksort();
	return 0;
}
