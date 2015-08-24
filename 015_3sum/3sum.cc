/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

// Star: 7.9.
// Info.: Adapted directly form LeetCode Discuss, which I can hardly come up with.
// Info.: There's a faster solution.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> & nums) {
  std::vector<std::vector<int> > triplets;
  int size = nums.size();
  if (size < 3)
    return triplets;

  sort(nums.begin(), nums.end());
  for (int i=0; i<size-2; ++i)
    if (i==0 || (i>0 && nums[i]!=nums[i-1])) {    // Begin at the first different number in the subsequent numbers.
      int sum = 0-nums[i];
      int l = i+1;
      int r = size-1;
      while (l < r) {
        if (sum == nums[l]+nums[r]) {
          std::vector<int> triplet;
          triplet.push_back(nums[i]);
          triplet.push_back(nums[l]);
          triplet.push_back(nums[r]);
          triplets.push_back(triplet);
          while (l<r && nums[l]==nums[l+1]) ++l;  // Don't code in ambiguous style.
          while (l<r && nums[r]==nums[r-1]) --r;
          ++ l; -- r;
        } else if (sum > nums[l]+nums[r])
          ++ l;
        else
          -- r;
      }
    }
  return triplets;
}

int main(int argc, char * argv[]) {

  if (argc < 4) {
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

  std::cout << "Triplets whose sum is 0 from array above are: " << std::endl;
  std::vector<std::vector<int> > triplets = threeSum(iv);
  for (int i=0; i<triplets.size(); ++i)
    std::cout << triplets[i][0] << ' ' << triplets[i][1] << ' ' << triplets[i][2] << std::endl;

  return 0;
}

