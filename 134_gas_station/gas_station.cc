/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 

You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

// Star: 9.0.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual int canCompleteCircuit(std::vector<int> & gas, std::vector<int> & cost) = 0; // Pure virtual, or Solutionx may not have data members.
};

// From LeetCode Discuss.
class Solution0 : public Solution {
  public:
    int canCompleteCircuit(std::vector<int> & gas, std::vector<int> & cost) {
      int start = 0, tank = 0, total = 0;
      for (size_t i=0; i<gas.size(); ++i)
        if ((tank += gas[i] - cost[i]) < 0) {
          total += tank;
          start = i+1;    // If one cannot reach B starting from A, then he cannot reach B from any station between A and B.
          tank = 0;
        }
      return total+tank >= 0 ? start : -1;   // If total gas is greater than total cost then there must be a solution.
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

  // Get the gas array.
  std::cout << "Please input the gas array: ";
  std::vector<int> gas;
  int i = 0;
  while (std::cin >> i)
    gas.push_back(i);
  std::cout << "The gas array you input is: ";
  for (auto itr=gas.begin(); itr!=gas.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;
  // Get the cost array.
  std::cout << "Please input the cost array: ";
  std::cin.clear();
  std::vector<int> cost;
  while (std::cin >> i)
    cost.push_back(i);
  std::cout << "The cost array you input is: ";
  for (auto itr=cost.begin(); itr!=cost.end(); ++itr)
    std::cout << ' ' << *itr;
  std::cout << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  //Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    int idx = solutions[si]->canCompleteCircuit(gas, cost);
    if (idx != -1)
      std::cout << "Starting from the " << idx << "th station, you can travel around the circuit once." << std::endl;
    else
      std::cout << "You cannot travel around the circuit starting from any station." << std::endl;
  }

  return 0;
}
