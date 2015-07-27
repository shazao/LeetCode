/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

// Star: 6.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int titleToNumber(std::string s) {
  if (s.empty() == true)
    return 0;

  int number = 0;
  int weight = 1;
  for (int i=s.size()-1; i>=0; --i) {
    number += (s[i]-'A'+1)*weight;
    weight *= 26;
  }
  return number;
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    std::cout << "Please specify the correct parameter." << std::endl;
    return -1;
  }

  std::string s(argv[1]);
  std::cout << argv[1] << " -> " << titleToNumber(s) << std::endl;

  return 0;
}
