#include "libal.c"
#include "minitest.h"

void test_counting_sort(void)
{
	START("COUNTING_SORT");
	int arr[] = {2,5,3,0,2,3,0,3};
	int B[] = {0,0,0,0,0,0,0,0};
	int wanted[] = {0,0,2,2,3,3,3,5};
	int arr_size = sizeof(arr)/sizeof(int);
	int k = 5;

	Countingsort(arr,B,k,arr_size);
	check_arrs(B,wanted,arr_size);
}

int main(int argc, char *argv[])
{
	test_counting_sort();
	return 0;
}
