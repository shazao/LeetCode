/*
Follow up for "Remove Duplicates":

What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums 

being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

// Star: 7.
// Info.: One-time pass.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int removeDuplicates(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int removeDuplicates(std::vector<int> & nums) {
      size_t size = nums.size();
      if (size <= 2) return size;
      bool twice = nums[0]==nums[1];
      size_t length = 2;
      int element = nums[1];
      for (size_t i=2; i<size; ++i)
        if (element != nums[i]) {
          element = nums[length++] = nums[i];
          twice = false;
        } else if (twice == false) {
          element = nums[length++] = nums[i];
          twice = true;
        } else {
        }
      return length;
    }
};

// From LeetCode Discuss, more concise.
class Solution1 : public Solution {
  public:
    int removeDuplicates(std::vector<int> & nums) {
      int l = 0;
      for (int i=0; i<nums.size(); ++i)
        if (l<2 || nums[i]>nums[l-2])
          nums[l++] = nums[i];
      return l;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  // Get an array.
  std::cout << "Please input the array: ";
  std::vector<int> iv;
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);
  std::cout << "The array you input is: ";
  for (auto itr=iv.begin(); itr!=iv.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<int> ivv(iv);
    size_t length = solutions[si]->removeDuplicates(ivv);
    std::cout << "The length of the array removed duplicates is " << length << ".\n";
    std::cout << "Its content is: ";
    for (size_t i=0; i<length; ++i)
      std::cout << ' ' << ivv[i];
    std::cout << std::endl;
  }

  return 0;
}
