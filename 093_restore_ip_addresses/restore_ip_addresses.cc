/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

// Star: 9.0.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "..\Profiler.h"

class Solution {
  public:
    virtual std::vector<std::string> restoreIpAddresses(std::string s) = 0; // Pure virtual, or Solutionx may not have data members.
};

// Iterative method: 4 ms.
class Solution0 : public Solution {
  public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
      std::vector<std::string> rst;
      size_t length = s.length();
      if (length < 4 || length > 12) return rst;
      for (size_t i=1; i<4 && i<length-2; ++i)
        for (size_t j=i+1; j<i+4 && j<length-1; ++j)
          for (size_t k=j+1; k<j+4 && k<length; ++k) {
            std::string s0 = s.substr(0, i);
            std::string s1 = s.substr(i, j-i);
            std::string s2 = s.substr(j, k-j);
            std::string s3 = s.substr(k, length-k);
            if (isValid(s0) && isValid(s1) && isValid(s2) && isValid(s3))
              rst.push_back(s0 + '.' + s1 + '.' + s2 + '.' +s3);
          }
      return rst;
    }
  private:
    bool isValid(std::string s) {
      if (s.empty() || s.size() > 3 ||
          s[0]=='0' && s.size()>1 ||
          s.size()==3 && (s[0]-'0')*100 + (s[1]-'0')*10 + s[2]-'0' > 255)
        return false;
      else return true;
    }
};

// Recursive method(backtracking): 4 ms.
class Solution1 : public Solution {
  public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
      std::vector<std::string> rst;
      restoreIp(rst, s, 0, 0, "");
      return rst;
    }

  private:
    void restoreIp(std::vector<std::string> & ips, std::string & s, size_t idx, size_t count, std::string ip) {
      if (count > 4) return;
      if (count==4 && idx==s.size()) ips.push_back(ip);

      for (size_t i=1; i<=3; ++i) {
        if (idx+i > s.size()) break;
        std::string ss = s.substr(idx, i);
        if (i!=1 && ss[0]=='0' ||
            i==3 && (ss[0]-'0')*100 + (ss[1]-'0')*10 + ss[2]-'0' > 255)
          continue;
        restoreIp(ips, s, idx+i, count+1, ip+ss+(count==3 ? "" : "."));
      }
      return;
    }
};

int main(int argc, char * argv[]) {

  if (argc != 1) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::cout << "Please input the IP address w/o dots: ";
  std::string s;
  std::cin >> s;
  std::cout << "The IP address you input is: " << s << std::endl;

  std::vector<Solution*> solutions;
  Solution0 s0; solutions.push_back(&s0);
  Solution1 s1; solutions.push_back(&s1);
  for (size_t si=0; si<solutions.size(); ++si) {
    std::cout << "\n\t\t=== Solution " << si << " ===\n" << std::endl;
    Profiler perf;
    std::vector<std::string> ips = solutions[si]->restoreIpAddresses(s);
    std::cout << "The possible IPs are: " << std::endl;
    for (size_t i=0; i<ips.size(); ++i)
      std::cout << ips[i] << std::endl;
    std::cout << "Total " << ips.size() << "." << std::endl << std::endl;
  }

  return 0;
}
