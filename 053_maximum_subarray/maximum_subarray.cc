/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// Star: 8.5.
// Info.: TODO Solve it using devide and conquer.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int maxSubArray(std::vector<int> & nums) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int maxSubArray(std::vector<int> & nums) {
      int sum = nums[0];
      int largest_sum = nums[0];
      for (size_t i=1; i<nums.size(); ++i) {
        int sum_ = sum + nums[i];
        if (sum_ > nums[i]) sum = sum_;
        else                sum = nums[i];

        if (largest_sum < sum)
          largest_sum = sum;
      }

      return largest_sum;
    }
};

// Similar to Solution0 but modified original nums vector; But runs slower.
class Solution1 : public Solution {
  public:
    int maxSubArray(std::vector<int> & nums) {
      int largest_sum = nums[0];
      for (size_t i=1; i<nums.size(); ++i) {
        if (nums[i-1] > 0) nums[i] += nums[i-1];
        if (nums[i] > largest_sum) largest_sum = nums[i];
      }
      return largest_sum;
    }
};

// TODO Store the subarray is a little more complex.
class Solution2 : public Solution {
  public:
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  std::cout << "\nPlease input the array: ";
  int i = 0;
  while (std::cin >> i)
    iv.push_back(i);

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "Within array above, the contiguous subarray has the largest sum is: ";
    int ls = solutions[si]->maxSubArray(iv);
    std::cout << "The largest sum is " << ls << std::endl << std::endl;
  }

  return 0;
}


// Reference: 
/*
greedy:

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, min = 0, res = A[0];
        for(int i = 0; i < n; i++) {
            sum += A[i];
            if(sum - min > res) res = sum - min;
            if(sum < min) min = sum;
        }
        return res;
    }
};
The idea is to find the largest difference between the sums when you summing up the array from left to right. 

The largest difference corresponds to the sub-array with largest sum. I worked it out independently although 

It is very close to lucastan's solution https://oj.leetcode.com/discuss/11288/simple-o-n-c-solution-no-dp-no-divide-and-conquer

divide and conquer:

struct val {
    int l, m, r, s;
    val(int l, int m, int r, int s):l(l), m(m), r(r), s(s){}
};

class Solution {
public:
    val dac(int A[], int n) {
        if(n == 1) return val(A[0], A[0], A[0], A[0]);
        val v1 = dac(A, n / 2), v2 = dac(A + n / 2, n - n / 2);
        int l, m, r, s;
        l = max(v1.l, v1.s + v2.l);
        m = max(v1.r + v2.l, max(v1.m, v2.m));
        r = max(v2.r, v1.r + v2.s);
        s = v1.s + v2.s;
        return val(l, m, r, s);
    }
    int maxSubArray(int A[], int n) {
        val v = dac(A, n);
        return v.m;
    }
};
the idea is: for each sub array we calculate 4 values in O(1) time based on the return values of its two halves. 

The meaning of the values:

l: the sum of the sub array with largest sum starting from the first element
m: the sum of the sub array with largest sum
r: the sum of the sub array with largest sum ending at the last element
s: the sum of the whole array
the recursive relation is clear in the code.
*/
