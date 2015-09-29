/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/

// Star: 8.2.
// Info.: The sortString function is worth noting.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string> & strs) = 0; // Pure virtual, or Solutionx may not have data members.
};

class Solution0 : public Solution {
  public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string> & strs) {
      std::vector<std::vector<std::string> > result;
      std::unordered_map<std::string, std::vector<std::string> > um;
      for (size_t i=0; i<strs.size(); ++i) {
        std::string sorted_str = sortString(strs[i]);
        um[sorted_str].push_back(strs[i]);
      }

      result.resize(um.size());
      int i = 0;
      for (auto umi=um.begin(); umi!=um.end(); ++umi, ++i) {
        sort(umi->second.begin(), umi->second.end());
        result[i].swap(umi->second);
      }
      return result;
    }
  private:
    std::string sortString(std::string & str) {
      std::string sorted_str;
      int count[26] = { 0 };
      for (size_t i=0; i<str.size(); ++i)
        ++ count[str[i]-'a'];

      for (int i=0; i<26; ++i)
        for (int j=0; j<count[i]; ++j)
          sorted_str.push_back('a'+i);
      return sorted_str;
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
  std::vector<std::string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" }; 
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::vector<std::string> > anagram_groups = solutions[si]->groupAnagrams(strs);
    std::cout << "The groups of anagrams are: " << std::endl;
    for (auto agi=anagram_groups.begin(); agi!=anagram_groups.end(); ++agi) {
      for (size_t i=0; i<agi->size(); ++i)
        std::cout << ' ' << (*agi)[i];
      std::cout << std::endl;
    }
  }

  return 0;
}
