/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 

design an algorithm to find the maximum profit.
*/

// Star: 8.0;
// Info.: One-time pass by myself.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int maxProfit(std::vector<int> & prices) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    int maxProfit(std::vector<int> & prices) {
      int max_profit = 0, max_price_so_far = 0;
      for (int i=prices.size()-1; i>=0; --i)
        if (prices[i] > max_price_so_far) max_price_so_far = prices[i];
        else {
          int profit = max_price_so_far - prices[i];
          max_profit = profit>max_profit ? profit : max_profit;
        }
      return max_profit;
    }
};

// Nearly same code, but faster.
class Solution1 : public Solution {
  public:
    int maxProfit(std::vector<int> & prices) {
      int max_profit = 0, max_price_so_far = 0;
      for (int i=prices.size()-1; i>=0; --i) {
        max_price_so_far = std::max(prices[i], max_price_so_far);
        max_profit = std::max(max_price_so_far-prices[i], max_profit);
      }
      return max_profit;
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
    std::cout << "The maximum profit is: " << solutions[si]->maxProfit(iv) << std::endl << std::endl;
  }

  return 0;
}
