/*
Follow up for "Search in Rotated Sorted Array":

What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

// Star: 8.
// Info.: Just used a plain method to get the pivot index.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual bool search(std::vector<int> & nums, int target) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    bool search(std::vector<int> & nums, int target) {
      if (nums.empty()) return false;
      size_t size = nums.size();
      // Get pivot index.
      size_t pi = 0;    // Pivot index.
      for (size_t i=1; i<size; ++i)
        if (nums[i] < nums[i-1]) {
          pi = i;
          break;
        }
      // Normal binary search.
      int lo = target>nums[size-1] ? 0 : pi;
      int hi = target<=nums[size-1] ? size-1 : pi-1;
      while (lo <= hi) {
        int m = lo + ((hi-lo)>>1);
        if (target < nums[m]) hi = m - 1;
        else if (target > nums[m]) lo = m + 1;
        else return true;
      }
      return false;
    }
};

class Solution1 : public Solution {
  public:
    
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

  std::cout << std::endl << "Please input the target: ";
  int target = 0;
  std::cin.clear();
  std::cin.sync();
  std::cin >> target;
  std::cout << "The target you input is: " << target << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    bool r = solutions[si]->search(iv, target);
    if (r)
      std::cout << std::endl << "Target found!" << std::endl;
    else
      std::cout << "Target not found!" << std::endl;
  }

  return 0;
}
