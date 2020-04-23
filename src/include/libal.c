#include "libal.h"
#include <stdio.h>


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
