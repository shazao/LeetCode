/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

// Star: 7.5.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Solution 0: A straightforward but awkward method. 
// Pass on my PC, but RE(Runtime Error) on LeetCode.
//bool isIsomorphic(char * s, char * t) {
//  if (s==NULL && t==NULL)
//    return true;
//
//  char * ss = s;
//  char * tt = t;
//  int len = strlen(s);
//
//  bool * visited = (bool *)malloc(sizeof(bool) * len);
//  int i = 0;
//  for (; i<len; ++i)
//    visited[i] = false;
//
//  while (*ss) {
//    if (*ss!=*tt && *visited==false) {
//      char c = *ss;
//      int j = 0;
//      while (ss[j]) {
//        if (ss[j]==c && visited[j]==false) {
//          ss[j] = *tt;
//          visited[j] = true;
//        }
//        ++ j;
//      }
//    }
//    ++ ss;
//    ++ tt;
//    ++ visited;
//  }
//
//  free(visited);
//  if (strcmp(s, t) == 0)
//    return true;
//  else
//    return false;
//}

// Solution 1: Method from LeeCode Discuss.
// To check both replacement from s to t and replacement from t to s, 
// because of "No two characters may map to the same character".
bool isIsomorphic(char * s, char * t) {
  if (s==NULL && t==NULL)
    return true;

  char map_s[256] = { 0 };
  char map_t[256] = { 0 };
  while (*s) {
    if (map_s[*s]!=0 && map_s[*s]!=*t)
      return false;
    if (map_t[*t]!=0 && map_t[*t]!=*s)
      return false;
    map_s[*s] = *t;
    map_t[*t++] = *s++;
  }

  return true;
}

void main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  char * s = argv[1];
  char * t = argv[2];
  printf("\"%s\" and \"%s\" ", s, t);
  printf(" %s isomorphic.\n", isIsomorphic(s, t)?"is":"is not");

}

/* Another solution from Discuss
bool isIsomorphic(string s, string t) {
        char map_s[128] = { 0 };
        char map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;    
    }
*/
