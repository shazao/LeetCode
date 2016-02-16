/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

// Star: 8.7.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <assert.h>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int search(std::vector<int> & nums, int target) = 0; // Pure virtual, or Solutionx may not have data members.
};

/* My solution, tried 4 times, quite ugly code.
 * Actually, I can optimize it after I got pi since I know
 * which part the target is in: before pi or after pi. And 
 * then use normal binary search. */
class Solution0 : public Solution {
  public:
    int search(std::vector<int> & nums, int target) {
      if (nums.empty()) return -1;
      size_t size = nums.size();
      size_t pi = 0;    // Pivot index.
      for (size_t i=1; i<size; ++i)
        if (nums[i] < nums[i-1]) {
          pi = i;
          break;
        }
      int l = pi, r = pi - 1;
      if (r < 0) r = size-1;
      bool two_sides = l>r;
      while (l<=r || two_sides) {
        int m = 0;
        if (l <= r)
          m = l + ((r-l)>>1);
        else
          m = l + ((size+r-l)>>1);

        if (m < 0) m += size;
        if (m >= size) m -= size;

        if (target > nums[m])       l = m+1;
        else if (target < nums[m])  r = m-1;
        else                        return m;

        if (two_sides && l>=size) { l -= size; two_sides = false; }
        if (two_sides && r<0) { r += size; two_sides = false; }
        if (two_sides && l<=r+1) two_sides = false;     // l and r go same side.
      }
      return -1;
    }
};

// Adapted from LeetCode Discuss.
class Solution1 : public Solution {
  public:
    int search(std::vector<int> & nums, int target) {
      // Get pivot index using binary search.
      size_t size = nums.size();
      int lo = 0, hi = size-1;
      while (lo < hi) {
        int m = lo + ((hi-lo)>>1);
        if (nums[m] > nums[hi]) lo = m + 1;
        else hi = m;
      }
      size_t pi = lo;
      // Normal binary search.
      lo = target>nums[size-1] ? 0 : pi;
      hi = target<=nums[size-1] ? size-1 : pi-1;
      while (lo <= hi) {
        int m = lo + ((hi-lo)>>1);
        if (target < nums[m]) hi = m - 1;
        else if (target > nums[m]) lo = m + 1;
        else return m;
      }
      return -1;
    }
};

// A brilliant solution from LeetCode Discuss.
class Solution2 : public Solution {
  public:
    int search(std::vector<int> & nums, int target) {
      size_t n = nums.size();
      int lo=0,hi=n-1;
      // find the index of the smallest value using binary search.
      // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
      // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
      while(lo<hi){
        int mid=(lo+hi)/2;
        if(nums[mid]>nums[hi]) lo=mid+1;
        else hi=mid;
      }
      // lo==hi is the index of the smallest value and also the number of places rotated.
      int rot=lo;
      lo=0;hi=n-1;
      // The usual binary search and accounting for rotation.
      while(lo<=hi){
        int mid=(lo+hi)/2;
        int realmid=(mid+rot)%n;    // Note.
        if(nums[realmid]==target)return realmid;
        if(nums[realmid]<target)lo=mid+1;
        else hi=mid-1;
      }
      return -1;
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

  std::cout << std::endl << "Please input the target: ";
  int target = 0;
  std::cin.clear();
  std::cin.sync();
  std::cin >> target;
  std::cout << "The target you input is: " << target << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  Solution1 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    int r = solutions[si]->search(iv, target);
    if (r != -1)
      std::cout << std::endl << "Target found at index " << r << '.' << std::endl;
    else
      std::cout << "Target not found!" << std::endl;
  }

  return 0;
}
