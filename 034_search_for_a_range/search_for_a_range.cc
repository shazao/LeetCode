/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

// Star: 7.5.
// Info.: One-time pass; Binary search algorithm is worth trying again.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int binarySearch(std::vector<int> & nums, int target, int l, int r) {
  while(l <= r) {
    int mid = l+(r-l)/2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] > target)
      r = mid-1;
    else 
      l = mid+1;
  }
  return -1;
}

std::vector<int> searchRange(std::vector<int> & nums, int target) {
  int l = -1, r = -1;
  std::vector<int> range;
  int size = nums.size();
  range.push_back(l); range.push_back(r);
  int ff = binarySearch(nums, target, 0, size-1);
  if (ff == -1)
    return range;

  l = r = ff;
  while (l-1>=0 && nums[l]==nums[l-1])
    l = binarySearch(nums, target, 0, l-1);
  while (r+1<size && nums[r]==nums[r+1])
    r = binarySearch(nums, target, r+1, size-1);
  range[0] = l;
  range[1] = r;
  return range;
}

int main(int argc, char * argv[]) {

  if (argc > 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }
  std::cout << "Please input an integer array in ascending order and repeat one of its value: ";
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

  std::vector<int> range = searchRange(iv, target);
  std::cout << "The range of " << target << " is: " << range[0] << ' ' << range[1] << '.' << std::endl;

  return 0;
}

