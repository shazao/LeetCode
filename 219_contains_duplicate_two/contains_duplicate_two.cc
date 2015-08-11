/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

// Star: 6.8.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_set>

//bool containsNearbyDuplicate(std::vector<int> & nums, int k) {
//  std::unordered_set<int> us;
//  for (size_t i=0; i<=k && i<nums.size(); ++i)
//    if (us.find(nums[i]) != us.end())
//      return true;
//    else
//      us.insert(nums[i]);
//
//  for (size_t i=k+1; i<nums.size(); ++i) {
//    us.erase(nums[i-k-1]);
//    if (us.find(nums[i]) != us.end())
//      return true;
//    else
//      us.insert(nums[i]);
//  }
//  return false;
//}

// A more concise one.
bool containsNearbyDuplicate(std::vector<int> & nums, int k) {
  if (k <= 0)
    return false;

  std::unordered_set<int> us;
  for (size_t i=0; i<nums.size(); ++i) {
    if (i > k)
      us.erase(nums[i-k-1]);

    if (us.find(nums[i]) != us.end())
      return true;
    else
      us.insert(nums[i]);
  }
  return false;
}

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc-1; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";

  int k = std::atoi(argv[argc-1]);
  std::cout << (containsNearbyDuplicate(iv, k)?"contains ":"doesn't contain ") 
    << "duplicates within consecutive " << k+1 << " integers." << std::endl;

  return 0;
}
