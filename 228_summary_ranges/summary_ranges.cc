/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

// Star: 7.5.
// Info.: Has requirement on compilor.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

//std::string to_string(int i) {
//  std::string str;
//  if (i == 0) {
//    str.push_back('0');
//    return str;
//  }
//
//  int sign = i<0?-1:1;
//  i = i<0?-i:i;
//  while (i) {
//    int m = i%10;
//    str.push_back(m+'0');
//    i /= 10;
//  }
//  if (sign < 0)
//    str.push_back('-');
//  reverse(str.begin(), str.end());
//  return str;
//}

std::vector<std::string> summaryRanges(std::vector<int> & nums) {
  const int n = nums.size();
  std::vector<std::string> ranges;
  if (n == 0)
    return ranges;

  int b = 0, e = 0;
  while (e < n) {
    while (e+1<n && nums[e]+1==nums[e+1])
      ++ e;
    if (b == e)
      ranges.push_back(std::to_string(nums[b]));
    else
      ranges.push_back(std::to_string(nums[b]) + "->" + std::to_string(nums[e]));
    b = ++e;
  }

  return ranges;
}

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  for (int i=1; i<argc; ++i)
    iv.push_back(std::atoi(argv[i]));
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << iv[i] << " ";
  std::cout << std::endl;

  std::cout << "Ranges: " << std::endl;
  std::vector<std::string> ranges = summaryRanges(iv);
  for (size_t i=0; i<ranges.size(); ++i)
    std::cout << ranges[i] << std::endl;

  return 0;
}

