/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Star: 7.5.
// Info.: Not easy to get through.

// Solution 0: A little awkward.
//bool isAlpabet(char c) {
//  if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
//    return true;
//  else
//    return false;
//}
//
//bool isNumeric(char c) {
//  if (c>='0' && c<='9')
//    return true;
//  else 
//    return false;
//}
//
//bool isPalindrome(char * s) {
//  if (s == NULL)
//    return true;
//
//  char * ss = s + strlen(s) - 1;
//  while (ss >= s) {
//    while (!isAlpabet(*ss) && !isNumeric(*ss) && ss>=s)
//      -- ss;
//    while (!isAlpabet(*s) && !isNumeric(*s) && *s!='\0')
//      ++ s;
//
//    if (ss >= s)    // Note 0: The comparison below is based on this condition.
//      if (isNumeric(*s) && isNumeric(*ss)) {    // Note 1: Note this brace.
//        if (*s != *ss)
//          return false;
//      } else if (isAlpabet(*s) && isAlpabet(*ss)) {
//        if (!(*s==*ss || *s==*ss+'a'-'A' || *ss==*s+'a'-'A'))
//          return false;
//      } else
//        return false;
//    -- ss;
//    ++ s;
//  }
//
//  return true;
//}

// Solution 1: Convert upper case to lower case.
bool isAlphanumeric(char c) {
  if ((c>='a' && c<='z') || (c>='0' && c<='9'))
    return true;
  else 
    false;
}

bool isPalindrome(char * s) {
  if (s == NULL)
    return true;

  char * ps = s;
  while (*ps)
    if (*ps>='A' && *ps<='Z')
      *ps++ += 'a' - 'A';
    else
      ++ ps;

  char * ss = s + strlen(s) - 1;
  while (ss >= s) {
    while (!isAlphanumeric(*ss) && ss>=s)
      -- ss;
    while (!isAlphanumeric(*s) && *s!='\0')
      ++ s;

    if (ss >= s)    // Note 0: The comparison below is based on this condition.
      if (*s != *ss)
        return false;
    -- ss;
    ++ s;
  }

  return true;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return;
  }

  printf("\"%s\" %s a palindrome.\n", argv[1], isPalindrome(argv[1])?"is":"is not");

}
