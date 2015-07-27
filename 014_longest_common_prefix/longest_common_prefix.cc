/* Write a function to find the longest common prefix string amongst an array of strings. */

#include <iostream>
#include <vector>
#include <string>

// Star: 7.

std::string longestCommonPrefix(std::vector<std::string> & strs) {

  if (strs.size() == 0)   // Note 2: Caused by Note 0.
    return "";
  else if (strs.size() == 1)    // Note 3: Caused by Note 1.
    return strs[0];

  int i = 0;
  bool end = false;
  for (;; ++i) {
    for (size_t j=0; j<strs.size()-1; ++j) {    // Note 0: strs.size()-1(May be quite large!).
      if (i == strs[j].length() || i == strs[j+1].length()) {   // Note 1.
        end = true;
        break;
      }
      if (strs[j][i] != strs[j+1][i]) {
        end = true;
        break;
      }
    }
    if (end)
      break;
  }

  std::string rs("");
  for (int j=0; j<i; ++j)
    rs += strs[0][j];

  return rs;
}

int main() {

  std::vector<std::string> sv;
  //sv.push_back("ab");
  //sv.push_back("abc");
  sv.push_back("");

  for (size_t i=0; i<sv.size(); ++i)
    std::cout << sv[i] << std::endl;
  std::cout << std::endl;

  std::cout << longestCommonPrefix(sv) << std::endl;

  return 0;
}
