/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// Star: 7.9.
// Info.: Solve it again!

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>

int threeSumClosest(std::vector<int> & nums, int target, std::vector<int> & triplet) {
  int sum = target?-target:INT_MAX;
  sort(nums.begin(), nums.end());
  for (size_t i=0; i<nums.size()-2; ++i) {
    size_t l = i+1;
    size_t r = nums.size()-1;
    while (l < r) {
      int s = nums[i] + nums[l] + nums[r];
      if (std::abs(s - target) < std::abs(sum - target)) {
        sum = s;
        if (sum == target)
          return sum;
        triplet.clear();
        triplet.push_back(nums[i]);triplet.push_back(nums[l]);triplet.push_back(nums[r]);
      }
      s>target ? --r : ++l;
    }
  }
  return sum;
}

int main(int argc, char * argv[]) {

  if (argc < 5) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  int i = 1;
  for (; i<argc-1; ++i)
    iv.push_back(std::atoi(argv[i]));
  int target = std::atoi(argv[i]);
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";
  std::cout << std::endl;
  std::cout << "Target: " << target << std::endl;

  std::cout << "Triplet whose sum is closest to specified target is: ";
  std::vector<int> triplet;
  int sum = threeSumClosest(iv, target, triplet);
  for (size_t i=0; i<triplet.size(); ++i)
    std::cout << triplet[i] << ' ';
  std::cout << std::endl;
  std::cout << "Sum: " << sum << "; Target: " << target << std::endl;

  return 0;
}

