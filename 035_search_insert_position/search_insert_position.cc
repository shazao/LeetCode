/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index 

where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

// Star: 7.7.
// Info.: One-time pass; Binary search algorithm is worth trying again.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>

int binarySearch(std::vector<int> & nums, int target, int l, int r) {
  int l0 = l, r0 = r;
  int mid = l + (r-l)/2;
  while (l <= r) {
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      r = mid - 1;
    else 
      l = mid + 1;
    mid = l + (r-l)/2;
  }
  if (r == l0-1)
    return l0;
  else if (l == r0+1)
    return r0+1;
  else {      // Note 0: If the target is not found and between two numbers, the last "mid" may be either one of the two numbers.
    if (nums[mid] > target)
      return mid;
    else 
      return mid+1;
  }
}

int searchInsert(std::vector<int> & nums, int target) {
  return binarySearch(nums, target, 0, nums.size()-1);
}

int main(int argc, char * argv[]) {

  if (argc > 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }
  std::cout << "Please input an integer array in ascending order and one integer to insert: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  int target = iv[iv.size()-1];
  iv.pop_back();
  std::cout << "Original vector:";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << ' ' << iv[i];
  std::cout << "; Target: " << target;
  std::cout << std::endl;

  std::cout << "The index of the target is: " << searchInsert(iv, target) << ' ' << std::endl;

  return 0;
}
