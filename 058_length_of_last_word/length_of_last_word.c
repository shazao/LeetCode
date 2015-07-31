/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5. */

// Star: 7.

#include <stdio.h>
#include <string.h>


// Solution 0: Forward traversal.
//int lengthOfLastWord(char * s) {
//
//  if (s == NULL)
//    return 0;
//
//  char * front = s;
//  char * rear = s;
//
//  while (*s) {
//    if (*s==' ' && *(s+1)!=' ' && *(s+1)!='\0')
//      rear = s+1;
//    else if (*s!=' ' && (*(s+1)==' '||*(s+1)=='\0'))
//      front = s+1;
//    ++ s;
//  }
//
//  return front - rear;
//}

// Solution 1: Backward traversal.
int lengthOfLastWord(char * s) {

  if (s==NULL)
    return 0;

  int sl = strlen(s);

  while (--sl>=0 && s[sl]==' ');
  if (sl < 0)
    return 0;

  int result = 1;
  while (--sl>=0 && s[sl]!=' ')
    ++ result;

  return result;
}

void main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct parameter.\n");
    return;
  }

  //char * s = "  Hello world! ";
  char * s = argv[1];

  printf("Length of last word of \"%s\" is %d.\n", s, lengthOfLastWord(s));

}
