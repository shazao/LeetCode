/* Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list. */

// Star: 6.5.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Solution 0.
//int * plusOne(int * digits, int digitsSize, int * returnSize) {
//    
//    if (digitsSize <= 0)
//    	return NULL;
//    
//    int i = 0;
//    for (; i<digitsSize; ++i)
//    	if (digits[i] != 9)
//    		break;
//    		
//    int * rtn = NULL;
//    if (i == digitsSize)
//    	*returnSize = digitsSize+1;
//    else
//    	*returnSize = digitsSize;
//    rtn = (int *)malloc(sizeof(int) * *returnSize);
//    
//    for (i=digitsSize-1; i>=0; --i)
//    	if (digits[i] != 9)
//    		break;
//    	else {
//    		if (*returnSize == digitsSize)
//    			rtn[i] = 0;
//    		else
//    			rtn[i+1] = 0;
//    	}
//    
//    if (i < 0)
//    	rtn[0] = 1;
//    else {
//    	int j = i;
//    	rtn[j--] = digits[i] + 1;
//    	for (; j>=0; --j)
//    		rtn[j] = digits[j];
//    }
//    
//    return rtn;    	
//}

// Solution 1.
int * plusOne(int * digits, int digitsSize, int * returnSize) {
    
    if (digitsSize <= 0)
    	return NULL;
    
    int i = 0;
    for (; i<digitsSize; ++i)
    	if (digits[i] != 9)
    		break;
    		
    int * rtn = NULL;
    if (i == digitsSize) {
    	*returnSize = digitsSize+1;
    	rtn = (int *)malloc(sizeof(int) * *returnSize);
      rtn[0] = 1;
      for (i=1; i<*returnSize; ++i)
        rtn[i] = 0;
      return rtn;
    } else {
    	*returnSize = digitsSize;
    	rtn = (int *)malloc(sizeof(int) * *returnSize);
      for (i=*returnSize-1; i>=0; --i) {
        if (digits[i] != 9) {
          rtn[i] = digits[i] + 1;
          break;
        }
        else
          rtn[i] = 0;
      }
      while (--i >= 0)
        rtn[i] = digits[i];
      return rtn;
    }
}

int main(int argc, char * argv[]) {

  if (argc != 2) {
    printf("Please specify the correct arguments.\n");
    return 0;
  }

  //char * s = "  Hello world! ";
  char * s = argv[1];
  int digitsSize = strlen(s);
  int * digits = (int *)malloc(sizeof(int) * digitsSize);
  int i = 0;
  for (; i<digitsSize; ++i)
  	digits[i] = s[i]-'0';
  	
  int returnSize = 0;
  int * rtn = plusOne(digits, digitsSize, &returnSize);
  
  char * ss = (char *)malloc(sizeof(char) * (returnSize+1));
  for (i=0; i<returnSize; ++i)
  	ss[i] = rtn[i] + '0';
  ss[i] = '\0';  

  printf("Plusing one to %s is %s.\n", s, ss);

  free(rtn);

  return 0;
  
}

// Reference
// C++ solution from LeetCode Discuss
/*
void plusone(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;

        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            carry = (++digits[i]%=10) == 0;
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
*/
