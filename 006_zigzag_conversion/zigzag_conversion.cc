/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". */

// Star: 7.

#include <iostream>
#include <vector>
#include <string>

std::string convert(std::string s, int numRows) {
  std::vector<std::string> sv;
  for (int i=0; i<numRows; ++i) 
    sv.push_back(std::string(""));
  int vector_idx = 0;
  bool incr = true;
  for (int i=0; i<s.length(); ++i) {
    sv[vector_idx] += s[i];
    if (incr)
      ++ vector_idx;
    else 
      -- vector_idx;

    if (vector_idx == numRows) {
      incr = false;
      vector_idx = numRows - 2;
    }
    if (vector_idx == -1) {
      incr = true;
      if (numRows != 1)
        vector_idx = 1;
      else 
        vector_idx = 0;
    }
  }

  std::string return_string("");
  for (int i=0; i<sv.size(); ++i)
    return_string += sv[i];

  return return_string;
}


int main() {

  std::string string = "PAYPALISHIRING";

  std::cout << convert(string, 1) << std::endl;
  std::cout << convert(string, 3) << std::endl;
  std::cout << convert(string, 15) << std::endl;

  return 0;
}
