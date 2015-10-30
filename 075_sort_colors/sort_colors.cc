/*
Given an array with n objects colored red, white or blue, sort them 

so that objects of the same color are adjacent, with the colors in 

the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

// Star: 9.0.
// Info.: Seems easy, but ... . 
// Do not use iterator but index when traverse vector.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "../Profiler.h"

class Solution {
  public:
    virtual void sortColors(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

// My wrong solution.
class Solution0 : public Solution {
  public:
    void sortColors(std::vector<int> & nums) {
      auto vi = nums.begin();   // "vector iterator".
      auto ri = nums.begin();   // Red iterator.
      auto bi = nums.end() - 1;     // Blue iterator; Note the "one off the end".
      //for ( ; vi<=bi; ++vi) {
      //  if (*vi == 0) {
      //    while (*ri == 0) ++ri;
      //    std::swap(*ri, *vi); ++ri;
      //  } else if (*vi == 2) {
      //    while (*bi == 2) --bi;
      //    if (*bi != 0) {
      //      std::swap(*bi, *vi); --bi;
      //    } else {
      //      std::swap(*ri, *bi); ++ri;
      //      std::swap(*bi, *vi); --bi;
      //    }
      //  }
      //  for (auto itr=nums.begin(); itr!=nums.end(); ++itr)
      //    std::cout << ' ' << *itr;
      //  std::cout << std::endl << std::endl;
      //}
      std::cout << vi - nums.begin() << std::endl;
      std::cout << ri - nums.begin() << std::endl;
      std::cout << bi - nums.begin() << std::endl;
    }
};

// Solution from LeetCode.
class Solution1 : public Solution {
  public:
    void sortColors(std::vector<int> & nums) {
      int red = 0, blue = nums.size() - 1;
      for (int idx=0; idx<=blue; ++idx) {
        while (nums[idx]==2 && blue>idx) std::swap(nums[idx], nums[blue--]);
        while (nums[idx]==0 && red<idx) std::swap(nums[idx], nums[red++]);
      }
    }
};

// Solution from LeetCode.
class Solution2 : public Solution {
  public:
    void sortColors(std::vector<int> & nums) {
      int red = 0, blue = nums.size() - 1;
      for (int idx=0; idx<=blue; )
        if (nums[idx] == 0)
          std::swap(nums[idx++], nums[red++]);
        else if (nums[idx] == 2)
          std::swap(nums[idx], nums[blue--]);
        else
          ++idx;
    }
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

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
  Solution2 s2; solutions.push_back(&s2);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    solutions[si]->sortColors(iv);
    std::cout << "Sorted colors array: ";
    for (auto itr=iv.begin(); itr!=iv.end(); ++itr)
      std::cout << ' ' << *itr;
    std::cout << std::endl << std::endl;
  }

  return 0;
}

/*
// two pass O(m+n) space
void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;

    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }

    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}

// one pass in place solution
void sortColors(int A[], int n) {
    int n0 = -1, n1 = -1, n2 = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == 0) 
        {
            A[++n2] = 2; A[++n1] = 1; A[++n0] = 0;
        }
        else if (A[i] == 1) 
        {
            A[++n2] = 2; A[++n1] = 1;
        }
        else if (A[i] == 2) 
        {
            A[++n2] = 2;
        }
    }
}

// one pass in place solution
void sortColors(int A[], int n) {
    int j = 0, k = n - 1;
    for (int i = 0; i <= k; ++i){
        if (A[i] == 0 && i != j)
            swap(A[i--], A[j++]);
        else if (A[i] == 2 && i != k)
            swap(A[i--], A[k--]);
    }
}

// one pass in place solution
void sortColors(int A[], int n) {
    int j = 0, k = n-1;
    for (int i=0; i <= k; i++) {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        else if (A[i] == 2)
            swap(A[i--], A[k--]);
    }
}
*/

