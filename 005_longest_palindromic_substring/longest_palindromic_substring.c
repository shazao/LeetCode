/*
Given a string S, find the longest palindromic substring in S. 

You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

// Star: 7.8.
// Info.: A little difficult to me.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int expandAroundCenter(char * s, int len, int a, int b) {
  while (a>=0 && b<=len && s[a]==s[b]) {
    -- a;
    ++ b;
  }
  return b - a -1;
}

char * longestPalindrome(char * s) {
  if (s == NULL)
    return NULL;

  int len = strlen(s);
  int start_position = 0;
  int max_len = 0;
  int i = 0;
  for (; i<len; ++i) {
    int l0 = expandAroundCenter(s, len, i, i);
    int l1 = expandAroundCenter(s, len, i, i+1);
    l0 = l0>l1 ? l0 : l1;
    if (l0 > max_len) {
      max_len = l0;
      start_position = i - (l0-1)/2;
    }
  }
  char * result = (char *)malloc((max_len+1)*sizeof(char));
  strncpy(result, &s[start_position], max_len);
  result[max_len] = '\0';
  return result;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  printf("Longest palindromic substring in \"%s\" is: %s.\n", argv[1], longestPalindrome(argv[1]));
}


// Reference
// http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html 
// http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html 
// http://www.felix021.com/blog/read.php?2040

// Highly-voted solution on LeetCode Discuss
// 0
/*
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
}
*/

// 1
/*
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};
*/

// Manacher’s algorithm. 
/*
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
*/
