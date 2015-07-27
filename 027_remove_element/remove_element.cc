/* Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. */ 

#include <stdio.h>
#include <iostream>
#include <vector>

// Star: 7.

int removeElement(std::vector<int>& nums, int val) {
	
	int length = nums.size();
	for (int i=0; i<length; ++i)
		if (nums[i] == val) {
			nums.erase(nums.begin() + i);
			-- length;
			-- i;			// Note 0.
		}
		
	return length;
}
	
	
int main() {
	
	//std::vector<int> a = {1, 3, 3, 1, 2, 2, 1};
	std::vector<int> a;
	a.push_back(3);
	a.push_back(3);
	int length = removeElement(a, 3);
	
	int i = 0;
	for (; i<length; ++i)
		printf("%d ", a[i]);
		
	printf("\n");
	
	return 0;
}
