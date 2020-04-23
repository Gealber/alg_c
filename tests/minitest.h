#ifndef _minitest_h
#define _minitest_h
#include <assert.h>
#include <stdio.h>


#define START(A) {\
	printf("----------------------------\n");\
	printf("Running test_%s...\n",A);\
}
static inline int check_arrs(int a[], int b[], int size)
{
	int i = 0;
	for(i = 0; i < size; i++) {
		assert(a[i] == b[i]);
		//printf("a[%d]=%d b[%d]=%d\n",i,a[i],i,b[i]);
	}
	printf("PASSED\n");
	return 0;
}


#endif
