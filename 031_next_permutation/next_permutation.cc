/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>

void nextPermutation(std::vector<int> & nums) {
  int i = nums.size()-1;
  // Find the longest descending sequence at the tail.
  while (i-1>=0 && nums[i]<=nums[i-1])
    -- i;
  if (i == 0) {
    sort(nums.begin(), nums.end());
    return;
  }

  // Find the minimum value in the descending sequence which is greater than nums[i-1].
  int min = INT_MAX;
  int min_idx = i;
  for (int j=i; j<nums.size(); ++j)
    if (nums[j]>nums[i-1] && nums[j]<min) {
      min = nums[j];
      min_idx = j;
    }

  int tmp = nums[i-1]; nums[i-1] = nums[min_idx]; nums[min_idx] = tmp;

  sort(nums.begin()+i, nums.end());
}

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";
  std::cout << std::endl;

  nextPermutation(iv);
  std::cout << "Next permutation is:";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << ' ' << iv[i];
  std::cout << std::endl;

  return 0;
}

