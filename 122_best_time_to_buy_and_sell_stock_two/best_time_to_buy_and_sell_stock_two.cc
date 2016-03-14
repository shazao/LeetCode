/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 

(ie, buy one and sell one share of the stock multiple times). However, you may not engage in 

multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

// Star: 8.3.
// Info.: One-time pass by myself.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int maxProfit(std::vector<int> & prices) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int maxProfit(std::vector<int> & prices) {
      int max_profit = 0;
      for (int i=1; i<prices.size(); ++i)
        if (prices[i] > prices[i-1])
          max_profit += prices[i] - prices[i-1];
      return max_profit;
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

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "The maximum profit is: " << solutions[si]->maxProfit(iv) << std::endl << std::endl;
  }

  return 0;
}
