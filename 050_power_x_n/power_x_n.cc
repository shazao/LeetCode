/*
Implement pow(x, n).
*/

// Star: 

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual double myPow(double x, int n) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    double myPow(double x, int n) {
      double result = 1;
      unsigned p = 0;
      if (n < 0) {
        p = -n;
        x = 1/x;
      } else if (n > 0) 
        p = n;     // Note 0: Conversion(int to unsigned int)!
      else {
        if (x)  return 1;
        else return 0;
      }

      while (p) {
        if (p & 0x01)
          result *= x;
        x *= x;
        p >>= 1;
      }
      return result;
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

  double x = 0;
  int power = 0;
  std::cout << "Input a double: ";
  std::cin >> x;
  std::cout << "Input a integer: ";
  std::cin >> power;

  std::cout << "The " << power << "th power of " << x << " is: " << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << solutions[si]->myPow(x, power) << std::endl;
  }

  return 0;
}
