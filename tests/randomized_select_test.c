#include "minitest.h"
#include "libal.c"
#include <assert.h>
#include <stdio.h>

void test_randomized_select(void)
{
	START("RANDOMIZED_SELECT");
	int arr[] = {2,4,1,8,9};
	int wanted = 4;
	int p = 0, r = 3, i = 3;

	int result = Randomized_Select(arr,p,r,i);
	assert(result == wanted);
	printf("PASSED\n");
}

int main(int argc, char *argv[])
{
	test_randomized_select();
	return 0;
}

