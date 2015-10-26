/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

// Star: 8.7.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int mySqrt(int x) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int mySqrt(int x) {
      if (!x) return x;

      int l = 0, r = (x>>1) + 1;
      while (l <= r) {
        int m = r - ((r-l)>>1);
        if (m > x/m)
          r = m - 1;
        else {
          if (m+1 > x/(m+1))
            return m;
          l = m + 1;
        }
      }
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

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    for (int i=0; i<=256; ++i)
      std::cout << ' ' << "sqrt(" << i << ") = " << solutions[si]->mySqrt(i) << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
