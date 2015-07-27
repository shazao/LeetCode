/* Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. */ 

#include <stdio.h>

// Star: 7.

void swap(int * a, int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
	
	int length = numsSize;
	
	for (int i=0; i<length; ++i)
		if (nums[i] == val) {
			while (nums[--length] == val && length>i);
			swap(&nums[i], &nums[length]);
		}
	
	return length;
}
				
void main() {
	
	int a[] = {1, 3, 3, 1, 2, 2, 1};
	int length = removeElement(a, 7, 1);
	
	int i = 0;
	for (; i<length; ++i)
		printf("%d ", a[i]);
		
	printf("\n");
	
}