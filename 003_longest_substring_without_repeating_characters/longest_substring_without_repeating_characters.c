/*
Given a string, find the length of the longest substring without repeating characters. 

For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 

For "bbbbb" the longest substring is "b", with the length of 1.
*/

// Star: 7.8.
// Info.: Worth trying again(Especially Solution 1); My first try is also not bad.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Solution 0: A straightforward method, not very efficient(Record whether the character appeared or not).
//int lengthOfLongestSubstring(char * s) {
//  if (s == NULL)
//    return 0;
//
//  int max_len = 0;
//  int len = strlen(s);
//  int hash[256];
//  memset(hash, 0, 256*sizeof(int));
//  int f = 0;
//  int b = 0;
//  while (s[f]) {
//    if (len-b <= max_len)
//      break;
//    if (hash[s[f]] == 0)
//      hash[s[f++]] = 1;
//    else {
//      if (f-b > max_len)
//        max_len = f-b;
//      while (s[b] != s[f])
//        hash[s[b++]] = 0;
//      hash[s[b++]] = 0;
//    }
//  }
//  return f-b>max_len ? f-b : max_len;
//}

// Solution 1: A much better solution from LeetCode Discuss(Record the last occurrence position).
int lengthOfLongestSubstring(char * s) {
  int position[256];
  memset(position, 0xff, 256*sizeof(int));
  int len = strlen(s);
  int max_len = 0;
  int i = 0;
  int start_position = i;
  for (; s[i]; ++i) {
    int lop = position[s[i]];   // last occurrence position
    if(lop!=-1 && lop<i) {
      if (max_len < i-start_position)
        max_len = i-start_position;
      if (lop+1 > start_position)
        start_position = lop+1;
    }
    position[s[i]] = i;
  }
  return max_len>i-start_position ? max_len : i-start_position;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  printf("The length of the longest substring without repeating characters in \"%s\" is %d.\n", argv[1], lengthOfLongestSubstring(argv[1]));

}
