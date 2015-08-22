/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

// Star: 7.7.
// Info.: Don't know how to solve it.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> & nums, int target) {
  std::vector<int> result;
  std::unordered_map<int, int> um;
  for (size_t i=0; i<nums.size(); ++i) {
    int component = nums[i];
    int another_component = target - component;
    if (um.find(another_component) != um.end()) {
      result.push_back(um[another_component] + 1);
      result.push_back(i + 1);
      return result;
    }
    um[component] = i;
  }
  return result;
}

int main(int argc, char * argv[]) {

  if (argc < 4) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc-1; ++i)
    iv.push_back(std::atoi(argv[i]));
  int target = std::atoi(argv[argc-1]);

  std::vector<int> idcs = twoSum(iv, target);
  std::cout << "The sum of " << idcs[0] << "th number and " << idcs[1] << "th number is " << target << std::endl;

  return 0;
}

