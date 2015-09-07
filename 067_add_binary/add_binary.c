/*  Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".*/

// Star: 7.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addBinary(char * a, char * b) {

  if (a == NULL)
    return b;
  if (b == NULL)
    return a;

  int la = strlen(a);
  int lb = strlen(b);
  int lmax = la>=lb ? la : lb;
  int lmin = la<=lb ? la : lb;

  // Process the common lower part shared by a and b.
  char * rtn = (char *)malloc(sizeof(char) * (lmax+1));   // Note 0: "lmax+1".
  rtn[lmax] = '\0';   // Note 1: Add the terminator first.
  int i = 0;
  char carry = 0;
  for (i=0; i<lmin; ++i) {
    char aa = a[la-i-1] - '0';
    char bb = b[lb-i-1] - '0';
    char sum = ((aa^bb^carry)&0x01) + '0';
    rtn[lmax-i-1] = sum;
    if (aa+bb+carry >= 2)
      carry = 1;
    else
      carry = 0;
  }

  // Process the remained significant part of the longer one.
  char * pc = NULL;
  if (la-i-1 < 0)
    pc = b+lb-i-1;
  else
    pc = a+la-i-1;
  for (i=0; i<lmax-lmin; ++i) {
    char pp = *pc-- - '0';
    char sum = pp^carry;
    rtn[lmax-lmin-1-i] = sum + '0';
    carry = pp&carry;
  }

  // Process overflow.
  if (carry) {
    char * rtn_ = (char *)malloc(sizeof(char) * (lmax+2));
    rtn_[0] = '1';
    memcpy(rtn_+sizeof(char), rtn, lmax+1);
    free (rtn);
    return rtn_;
  } else 
    return rtn;

}

int main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Please specify the correct arguments.\n");
    return 0;
  }

  char * a = argv[1];
  char * b = argv[2];
  char * c = addBinary(a, b);

  printf("Adding %s to %s is %s.\n", a, b, c);

  free(c);

  return 0;
}

// Reference 
// A C++ solution from LeetCode Discuss
/*
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};
*/
