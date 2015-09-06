/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters is just like on the telephone buttons as below:
2->abc, 3->def, 4->ghi, ..., 7->pqrs, ..., 9->wxyz.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

// Star: 7.5.
// Info.: Nearly one-time pass; The back-track method is interesting.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::string> letterCombinations(std::string digits);
};

class Solution0 : public Solution {
  public:
    std::vector<std::string> letterCombinations(std::string digits) {
      std::vector<std::string> result;
      if (digits.empty()) return result;
      const std::vector<std::string> map = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
      result.push_back("");
      for (size_t i=0; i<digits.size(); ++i) {
        int idx = digits[i]-'0';
        size_t last_size = result.size();
        size_t str_len = map[idx].size();
        size_t next_size = last_size * str_len;
        result.resize(next_size);
        for (int j=last_size-1; j>=0; --j)
          for (int k=0; k<str_len; ++k)
            result[str_len*(j+1)-1-k] = result[j]+map[idx][k];
      }
      return result;
    }
};

class Solution1 : public Solution {
  public:
    std::vector<std::string> letterCombinations(std::string digits) {
      std::vector<std::string> result;
      if (digits.empty()) return result;
      const std::vector<std::string> map = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
      std::string combination;
      letterCombinations(digits, 0, map, result, combination);
      return result;
    }

  private:
    void letterCombinations(std::string & digits, int idx, const std::vector<std::string> & map, std::vector<std::string> & result, std::string & combination) {
      if (!digits[idx]) {
        result.push_back(combination);
        return ;
      }
      std::string str = map[digits[idx]-'0'];
      for (size_t i=0; i<str.size(); ++i) {
        combination.push_back(str[i]);
        letterCombinations(digits, idx+1, map, result, combination);
        combination.pop_back();
      }
    }
};

int main(int argc, char * argv[]) {

  if (argc < 2) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::string s(argv[1]);
  std::cout << "Original string: " << s << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::cout << "All possible letter combinations that the number could represent are: " << std::endl;
    std::vector<std::string> sv = solutions[si]->letterCombinations(s);
    for (size_t i=0; i<sv.size(); ++i)
      std::cout << sv[i] << std::endl;
  }

  return 0;
}


// Reference: Three solutions from LeetCode Discuss.
//
// 0: Back-track.
/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(0>=digits.size()) return ret;

        const string map[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backTrackingFun(map,digits,"",ret);

        return ret;
    }

    void backTrackingFun(const string m[], const string &digits, string r, vector<string> &ret){
        int c=r.size();
        if(digits.size()==c){
            ret.push_back(r);
            return;
        }

        auto str = m[digits.at(c)-48];
        for(auto it=str.cbegin();it!=str.cend();++it){
            r.push_back(*it);
            backTrackingFun(m,digits,r,ret);
            r.pop_back();
        }
    }
};
*/

// 1: Iterative.
/*
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;
    }
    return res;
}
*/

// 2: Iterative(More efficient using std::vector::swap).
/*
vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}
*/
