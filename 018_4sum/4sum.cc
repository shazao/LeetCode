/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

// Star: 9.1.
// Info.: There's still faster solutions.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <time.h>  

using namespace std;
#include "LeetCodeDiscuss0.cc"

// Wrong solution.
//std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target) {
//  std::vector<std::vector<int> > quadruplets;
//  int size = nums.size();
//  sort(nums.begin(), nums.end());
//  for (int i=0; i<size-3; ++i)
//    if (i==0 || (i>0 && nums[i]!=nums[i-1])) {
//      int l = i+1;
//      int r = size-1;
//      while (l < r-1) {
//        std::vector<int> quadruplet;
//        int suml = nums[i]+nums[l]+nums[l+1]+nums[r];
//        int sumr = nums[i]+nums[l]+nums[r-1]+nums[r];
//        if (target>=suml && target<=sumr) {
//          int m = l+1;
//          while (m < r) {
//            int sum = nums[i]+nums[l]+nums[m]+nums[r];
//            if (sum == target) {
//              quadruplet.clear();
//              quadruplet.push_back(nums[i]); quadruplet.push_back(nums[l]);
//              quadruplet.push_back(nums[m]); quadruplet.push_back(nums[r]);
//              quadruplets.push_back(quadruplet);
//              ++ l;
//              break;
//            }
//            ++ m;
//          }
//          ++ l;
//        } else if (target < suml)
//          -- r;
//        else
//          ++ l;
//      }
//    }
//  return quadruplets;
//}

// Solution 0: From LeetCode Discuss; But TLE.
//std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target) {
//  std::vector<std::vector<int> > quadruplets;
//  int size = nums.size();
//  sort(nums.begin(), nums.end());
//  for (int i=0; i<size-3; ++i) {
//    int target0 = target - nums[i];
//    for (int j=i+1; j<size-2; ++j) {
//      int target1 = target0 - nums[j];
//      int l = j + 1;
//      int r = size - 1;
//      while (l < r) {
//        std::vector<int> quadruplet;
//        int sum = nums[l] + nums[r];
//        if (sum == target1) {
//          quadruplet.push_back(nums[i]); quadruplet.push_back(nums[j]); 
//          quadruplet.push_back(nums[l]); quadruplet.push_back(nums[r]); 
//          quadruplets.push_back(quadruplet);
//          while (l<r && nums[l]==quadruplet[2]) ++l;
//          while (l<r && nums[r]==quadruplet[3]) --r;
//        } else if (sum < target1)
//          ++ l;
//        else
//          -- r;
//      }
//      while (j+1<size && nums[j]==nums[j+1]) ++j;
//    }
//    while (i+1<size && nums[i]==nums[i+1]) ++i;
//  }
//  return quadruplets;
//}

// Solution 1: From http://blog.csdn.net/hcbbt/article/details/44063375.
// Still TLE.
//std::string to_string(int i) {
//  std::string str;
//  if (i < 0) {
//    i = -i;
//    str.push_back('-');
//  }
//  while (i) {
//    str.push_back(i%10 + '0');
//    i /= 10;
//  }
//  if (str[0] == '-')
//    reverse(str.begin()+1, str.end());
//  else
//    reverse(str.begin(), str.end());
//  return str;
//}
//
//std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target) {
//  std::vector<std::vector<int> > quadruplets;
//  if (nums.size() < 4) return quadruplets;
//  std::unordered_map<int, std::vector<std::vector<int> > > um;
//  std::unordered_set<std::string> quadruplet_set;
//  for (size_t i=0; i<nums.size()-1; ++i)
//    for (size_t j=i+1; j<nums.size(); ++j)
//      um[nums[i]+nums[j]].push_back(std::vector<int>({nums[i], i, nums[j], j}));
//
//  for (auto it=um.cbegin(); it!=um.cend(); ++it) {
//    int one = it->first;
//    auto another = um.find(target-one);
//    if (another != um.end()) {
//      std::vector<std::vector<int> > a = it->second;
//      std::vector<std::vector<int> > b = another->second;
//      for (size_t i=0; i<a.size(); ++i)
//        for (size_t j=0; j<b.size(); ++j) {
//          std::vector<int> aa = a[i];
//          std::vector<int> bb = b[j];
//          if (aa[1]!=bb[1] && aa[1]!=bb[3] && aa[3]!=bb[1] && aa[3]!=bb[3]) {
//            std::vector<int> quadruplet({aa[0], aa[2], bb[0], bb[2]});
//            sort(quadruplet.begin(), quadruplet.end());
//            std::string set_key;
//            for (int i=0; i<4; ++i)
//              set_key += to_string(quadruplet[i]);
//            if (quadruplet_set.find(set_key) == quadruplet_set.end()) {
//              quadruplets.push_back(quadruplet);
//              quadruplet_set.insert(set_key);
//            }
//          }
//        }
//    }
//  }
//  return quadruplets;
//}

// Solution 2: From LeetCode Discuss.
//std::vector<std::vector<int>> fourSum(std::vector<int> & nums, int target) {
//  std::vector<std::vector<int> > quadruplets;
//  int nums_size = nums.size();
//  if (nums_size < 4) return quadruplets;
//  sort(nums.begin(), nums.end());
//  std::unordered_map<int, std::vector<std::pair<int, int> > > sum_hash;
//  for (size_t i=0; i<nums_size-1; ++i)
//    for (size_t j=i+1; j<nums_size; ++j)
//      sum_hash[nums[i]+nums[j]].push_back(std::make_pair(i, j));
//
//  for (size_t i=0; i<nums_size-1; ++i) {
//    if (i>0 && nums[i]==nums[i-1]) continue;
//    for (size_t j=i+1; j<nums_size; ++j) {
//      if (j>i+1 && nums[j] == nums[j-1]) continue;
//      int sum_of_remaining_two = target - nums[i] - nums[j];
//      if (sum_hash.count(sum_of_remaining_two)) {
//        std::vector<std::pair<int, int> > sum_pairs = sum_hash[sum_of_remaining_two];
//        for (auto itr=sum_pairs.begin(); itr!=sum_pairs.end(); ++itr) {
//          int k = itr->first;
//          int l = itr->second;
//          if (k > j) {
//            if (!quadruplets.empty() && 
//                quadruplets.back()[0]==nums[i] && quadruplets.back()[1]==nums[j] &&
//                quadruplets.back()[2]==nums[k] && quadruplets.back()[3]==nums[l])
//              continue;
//            quadruplets.push_back(std::vector<int>({nums[i], nums[j], nums[k], nums[l]}));
//          }
//        }
//      }
//    }
//  }
//  return quadruplets;
//}

int main(int argc, char * argv[]) {

  if (argc < 5) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::vector<int> iv;
  int i = 1;
  for (; i<argc-1; ++i)
    iv.push_back(std::atoi(argv[i]));
  int target = std::atoi(argv[i]);
  std::cout << "Original vector: ";
  for (size_t i=0; i<iv.size(); ++i)
    std::cout << " " << iv[i];
  std::cout << "; Target: " << target << std::endl;

  std::cout << "Quadruplets whose sum is " << target << " from array above are: " << std::endl;
  clock_t s, e;  
  s = clock() ;   
  std::vector<std::vector<int> > quadruplets = fourSum(iv, target);
  e = clock() ;   
  for (int i=0; i<quadruplets.size(); ++i)
    std::cout << quadruplets[i][0] << ' ' << quadruplets[i][1] << ' ' << quadruplets[i][2] << ' ' << quadruplets[i][3] << std::endl;
  std::cout << (e-s)*1000.0/CLOCKS_PER_SEC << " milliseconds elapsed(" << e-s << " clock ticks)!" << std::endl;   

  return 0;
}

// Reference:
// http://blog.csdn.net/hcbbt/article/details/44063375
// http://www.cnblogs.com/Azhu/p/4154528.html
