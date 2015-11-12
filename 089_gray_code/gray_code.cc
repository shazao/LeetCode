/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 

print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <bitset>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<int> grayCode(int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<int> grayCode(int n) {
      std::vector<int> rst;
      if (!n) {
        rst.push_back(0);
        return rst;
      }

      rst.push_back(0); rst.push_back(1);
      for (int i=1; i<n; ++i) {
        size_t size = rst.size();
        for (size_t j=0; j<size; ++j)
          rst.push_back(rst[size-1-j]);
        for (size_t j=0; j<rst.size(); ++j)
          if (j >= size)
            rst[j] ^= 1<<i;
      }
      return rst;
    }
};

// Solution form LeetCode Discuss.
class Solution1 : public Solution {
  public:
    std::vector<int> grayCode(int n) {
      std::vector<int> result(1, 0);        
      for (int i = 0; i < n; i++) {
        int curCount = result.size();
        // push back all element in result in reverse order
        while (curCount) {
          curCount--;
          int curNum = result[curCount];
          curNum += (1<<i);
          result.push_back(curNum);
        } 
      }
      return result;
    }
};


int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the width of the Gray Code: ";
  int n = 0;
  std::cin >> n;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The Gray Code of n-bit are: ";
    std::vector<int> gray_code = solutions[si]->grayCode(n);
    for (auto & i : gray_code)
      std::cout << ' ' << i;
    std::cout << std::endl << "Its binary format is: " << std::endl;
    for (auto & i : gray_code)
      std::cout << std::bitset<8*sizeof(int)>(i) << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
