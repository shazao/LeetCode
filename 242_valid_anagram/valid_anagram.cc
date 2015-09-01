/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.
*/

// Star: 7.5.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void countCharInString(std::string s, int * set) {
  for (size_t i=0; i<s.size(); ++i)
    ++ set[s[i]-'a'];
}

bool isAnagram(std::string s, std::string t) {
  int ss[26] = { 0 };
  int st[26] = { 0 };
  countCharInString(s, ss);
  countCharInString(t, st);
  for (int i=0; i<26; ++i)
    if (ss[i] != st[i])
      return false;
  return true;
}
    
int main(int argc, char * argv[]) {

  if (argc != 3) {
    std::cout << "Please specify the correct arguments." << std::endl;
    return -1;
  }

  std::string s(argv[1]);
  std::string t(argv[2]);

  std::cout << '"' << s << "\" and \"" << t << '"' << (isAnagram(s, t)?" are ":" are not ") << "anagrams." << std::endl;

  return 0;
}
