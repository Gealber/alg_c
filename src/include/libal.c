#include "libal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**Max_heapify assumes that the binary trees rooted
 *  at LEFT(i) and RIGHT(i) are max-heaps, but that 
 *  a(i) might be smaller than its children.
 */
int Max_heapify(int *a, int i, int heap_size)
{
	/*compute left and right childs of node i*/
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = i;

	/*check if the left child is greater
	 * than his parent, if that's the case then
	 *make the largest equal left node in another
	 *case makes the index the largest*/
	if(l < heap_size && a[l] > a[i]) {
		largest = l;
	}	
	
	/*check now if the right child is greate
	 * than the current largest and update 
	 * the largest properly*/
	if(r < heap_size && a[r] > a[largest]) {
		largest = r;
	}
	
	/*Now if after all that the largest is not i
	 * then change a[i] with the largest and then
	 * call Max_heapify recursively taking the 
	 * parent node as the largest selected, in that way
	 * we make sure that is a max-heap*/
	if(i != largest ) {
		EXCHANGE(a[i],a[largest]);
		Max_heapify(a, largest, heap_size);	
	}
	return 0;
}

/*Build a max heap given an array*/
int Build_max_heap(int *arr, int heap_size)
{
	/*set the heap_size equal to array length
	 * */
	int i = 0;
	for(i = (heap_size-1)>>1; i > -1; i--) {
		Max_heapify(arr, i, heap_size);
	}
	return 0;
}

/*Sort the array using Heapsort algorithm*/
int Heapsort(int *arr, int heap_size)
{
	/*first we need to make sure that
	 * the given array is a max-heap*/
	Build_max_heap(arr, heap_size);
	int i = 0;
	/*after the Build_max_heap is used
	 *the greater element is in the 
	 *top of the array so we need to put
	 *that element in the final position of
	 *the array*/
	for(i = heap_size - 1; i > 0; i--) {
		EXCHANGE(arr[0],arr[i]);
		/*then we decress the size of the heap
		 * so when we heapify it again don't
		 * take into account the last element
		 * that we just reposition*/
		heap_size=heap_size-1;
		/*explicitly heapify the array*/
		Max_heapify(arr,0,heap_size);
	}

	return 0;
}

/*Quicksort perform the quicksort algorithm given an array of ints.
 * In case of sort the entire array the parameters must to be p=0 and
 * r=last index of the array*/
int Quicksort(int *arr, int p, int r)
{
	int q = 0;
	if(p < r) {
		q = Partition(arr,p,r);
		Quicksort(arr,p,q-1);
		Quicksort(arr,q+1,r);
	}
	return 0;
}

int Partition(int *arr,int p, int r)
{
	int x = arr[r];
	int i = p-1;
	int j = 0;

	for(j = p; j < r; j++) {
		if(arr[j] <= x) {
			i++;
			EXCHANGE(arr[i],arr[j]);
		}
	}

	EXCHANGE(arr[i+1],arr[r]);
	return i+1;
}

int Hoare_partition(int *arr, int p, int r)
{
	int x = arr[p];
	int i = p - 1;
	int j = r + 1;

	while (1) {
		do {
			i = i + 1;
		} while (arr[i] < x);

		do {
			j = j -1;
		} while (arr[j] > x);

		if(i < j) {
			EXCHANGE(arr[i], arr[j]);
		}
		 return j;
	}
	return -1;
}

int Randomized_partition(int *arr, int p, int r)
{
	int i =Random(p,r);
	EXCHANGE(arr[r],arr[i]);
	return Partition(arr,p,r);
}

/*A randomized version of quicksort, this is implemented 
 * because the average-case behavior of quicksort has a good
 * performance*/
int Randomized_quicksort(int *arr, int p, int r)
{
	int q = 0;
	if(p < r) {
		q = Randomized_partition(arr,p,r);
		Randomized_quicksort(arr,p,q-1);
		Randomized_quicksort(arr,q+1,r);
	}
	return 0;
}

int Countingsort(int *arr, int *b, int k, int arr_size)
{
	int c[k+1];
	int i = 0;
	for(i = 0; i < k+1; i++) {
		c[i] = 0;
	}

	int j = 0;
	for(j = 0; j < arr_size; j++) {
		c[arr[j]]++;
	}

	for(i = 1; i < k+1; i++) {
		c[i] = c[i] + c[i-1];
	}

	for(j = arr_size - 1; j >= 0; j--) {
		b[c[arr[j]]-1] = arr[j];
		c[arr[j]]--;
	}
	
	return 0;
}
